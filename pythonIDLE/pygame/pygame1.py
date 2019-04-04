import pygame
import sys

pygame.init()                               #初始化pygame
size = width,height = 600,400
speed = [-2,1]
bg = (255,255,255)
screen = pygame.display.set_mode(size)  #display.set_mode()创建Surface对象
pygame.display.set_caption('初次见面，请多多关照！')
turtle = pygame.image.load('turtle.png')#image.load()加载图片，完事会转换为surface对象
position = turtle.get_rect()#过得surface对象的矩形区域

while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            sys.exit()
    position = position.move(speed)
    if position.left < 0 or position.right > width:
        turtle = pygame.transform.flip(turtle,True,False)
        speed[0] = -speed[0]
    if position.top < 0 or position.bottom > height:
        speed[1] = -speed[1]
    screen.fill(bg)#填充背景白色
    screen.blit(turtle,position)#更新图像
    pygame.display.flip()#更新界面
    #pygame.time.delay(7)
    clock = pygame.time.Clock()
    clock.tick(100)
