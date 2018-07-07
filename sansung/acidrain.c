#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <linux/fb.h>
#include <pthread.h>
#include <time.h>

#define FBDEVFILE "/dev/fb"
#define yahoo 320, xahoo=465;

struct fb_var_screeninfo fbvar;
typedef unsigned char ubyte;
int fbfd,keyfd;
void tri(int argx,int argy);

unsigned short makepixel(ubyte r, ubyte g, ubyte b)
{
				return (unsigned short)(((r>>3)<<11)|((g>>2)<<5)|(b>>3));
}

void *Thread(ubyte *args)
{
				int i,j;
				unsigned short pix;
        int position;
				unsigned char arg[3];
				
				sleep(rand()%3);
				
				while(1)
				{
            arg[0]=(unsigned char)(rand()%255);
            arg[1]=(unsigned char)(rand()%255);
            arg[2]=(unsigned char)(rand()%255);
						position = rand()%610;
						printf("pid=%d,position=%d\n",getpid(),position);
						
						lseek(fbfd,position*2,SEEK_SET);
						pix=makepixel(arg[0],arg[1],arg[2]);
						
						for(i=0;i<30;i++)
						{
							for(j=0;j<30;j++)
							write(fbfd, &pix,2);
	  					lseek(fbfd,640*2-60,SEEK_CUR);
						}
						
						for(i=0;i<480;i++){	
					  
						lseek(fbfd,position*2+i*640*2,SEEK_SET);
						pix=makepixel(255,255,255);
						
						for(j=0;j<30;j++)
								write(fbfd,&pix,2);
	  			  
						lseek(fbfd,(31+i)*640*2+position*2,SEEK_SET);
						pix=makepixel(arg[0],arg[1],arg[2]);
						
						for(j=0;j<30;j++)
								write(fbfd,&pix,2);
						usleep(rand()%1000);
						}
				}
				
}

int main()
{
				int i,j,ret,num;
				char ch;
				unsigned short pixel;
			  pthread_t threads[10];
				
				fbfd = open(FBDEVFILE, O_RDWR);
				if(fbfd<0)
				{
								perror("fbdev open");
								exit(1);
				}
				keyfd= open("/dev/key_gpio",O_RDWR);
				if(keyfd<0)
				{
								perror("keydev open");
								exit(1);
				}
				

				ret=ioctl(fbfd, FBIOGET_VSCREENINFO,&fbvar);
				if(ret<0)
				{
								perror ("fbdev ioctl");
								exit(1);
				}
				
				pixel=makepixel(255,255,255);
				for ( j=0;j<640*480;j++)
				{
								lseek(fbfd,j*2,SEEK_SET);
								write(fbfd, &pixel,2);
				}	
				
			  srand(time(NULL));	
			  
				tri(0,0);
				 
				for(i=0;i<10;i++)
				{
					pthread_create(&threads[i],NULL,(void*(*)(void*))Thread,NULL);
				}

				while(1)
				{
					read(keyfd,&ch,1);
					num=(int)ch;
					printf("num= %d\n",num);
					switch(num)
					{
								case 1:
												tri(1,0);
												break;
								case 4:
												tri(0,1);
												break;
								case 6:
												tri(0,-1);
												break;
								case 9:
												tri(-1,0);
												break;
								case 11:
												close(keyfd);
												close(fbfd);
												return 0;				
								default : break;				
												
					}
					num=0;
				}
			

}
void tri(int argx,int argy)
{
				int i,j;
				unsigned short pixel;

				printf("hello tri\n");

				pixel=makepixel(255,255,255);
				for(i=0;i<15;i++)
				{
					lseek(fbfd,(xahoo+i)*fbvar.xres*2+(yahoo-i)*2,SEEK_SET);
					for(j=0;j<=(2*i+1);j++)
					write(fbfd,&pixel,2);
				}
				
				pixel=makepixel(255,0,0);
				for(i=0;i<15;i++)
				{
					if(argx==1)
					{
						lseek(fbfd,(xahoo+argy+i)*fbvar.xres*2+(yahoo+argx-i)*2,SEEK_SET);
						yahoo++;
					}
					else if(argx==-1)
					{
						lseek(fbfd,(xahoo+argy+i)*fbvar.xres*2+(yahoo+argx)*2-(i+1),SEEK_SET);
						yahoo--;			
					}
					for(j=0;j<=(2*i+1);j++)
					write(fbfd,&pixel,2);
				}
				
}
