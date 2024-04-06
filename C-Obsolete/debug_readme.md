
1. Pobierz 
[plik](https://github.com/majbthrd/pico-debug/releases/download/v10.05/pico-debug-gimmecache.uf2)

2. Załaduj poprzednio pobrany plik na pamięć płytki.

3. Otwórz *Pico - Developer PowerShell*

4. Wpisz w terminalu `openocd -f board/pico-debug.cfg`. **Nie zamykaj terminalu**.

5. Otwórz **nowy** terminal *Pico - Developer PowerShell*

6. Wpisz w terminalu `arm-none-eabi-gdb nazwa_twojego_pliku.elf`, otworzy to gdb.

7. Następnie wpisz `target extended-remote localhost:3333`

8. Następnie wpisz `load`

9. Wpisz `monitor reset init`

10. Teraz możesz używać już normalnie gdb.

Komendy: 
1. `start` - startuje program z breakpointem na main
2. `run` - uruchamia program bez breakpointa
2. `n` - wykonuje następną linię kodu
3. `s` - wskakuje w wykonywaną linijkę 
4. `b` - ustawia breakpoint, np. `b main` ustawia breakpoint na main
5. wciśnięcie enter - wykonuje poprzednią komendę
6. `trace` - pokazuje stack-frame
7. `where` - call-stack
8. `c` - kontynuje wykonanie programu
9. `clear` - usuwa wszystkie breakpointy
10. `print variable_name` - wyświetla zmienną, może nawet całą listę 

