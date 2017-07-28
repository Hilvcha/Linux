import pygame

class Ship():

    def __init__(self,screen):
        """init your ship and its setting"""
        self.screen = screen

        self.image=pygame.image.load('images/ship.bmp')
        self.rect= self.image.get_rect()
        self.screen_rect=screen.get_rect()

        self.rect.centerx = self.screen_rect.centerx
        self.rect.bottom = self.screen_rect.bottom

    def blitme(self):
        """draw the ship.bmp on the position you point"""
        self.screen.blit(self.image,self.rect) 