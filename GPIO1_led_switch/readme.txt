ustawienia:
- FLASH (rx) : ORIGIN = 0x08002000, LENGTH = 56K (wgrany bootloader)
- kwarc 12MHz




//-------------------------------------------------------------------
adres startowy flash w stm32 zmienia siê w pliku mem.ld
zmianê nale¿y wykonaæ gdy korzysta siê z bootloadera zajmuj¹cego miejsce na pocz¹tku pamiêci flash
zmiana(sekcja MEMORY):
  /*FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 64K*/
  FLASH (rx) : ORIGIN = 0x8002000, LENGTH = 56K

po zmianie CLEAN project i zbulidowaæ na nowo
dlapewnoœci sprawdziæ czy w pliku relase/projekt.map zmiani³ siê adres flash na w³aœciwy