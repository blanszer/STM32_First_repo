ustawienia:
- FLASH (rx) : ORIGIN = 0x08002000, LENGTH = 56K (wgrany bootloader)
- kwarc 12MHz




//-------------------------------------------------------------------
adres startowy flash w stm32 zmienia si� w pliku mem.ld
zmian� nale�y wykona� gdy korzysta si� z bootloadera zajmuj�cego miejsce na pocz�tku pami�ci flash
zmiana(sekcja MEMORY):
  /*FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 64K*/
  FLASH (rx) : ORIGIN = 0x8002000, LENGTH = 56K

po zmianie CLEAN project i zbulidowa� na nowo
dlapewno�ci sprawdzi� czy w pliku relase/projekt.map zmiani� si� adres flash na w�a�ciwy