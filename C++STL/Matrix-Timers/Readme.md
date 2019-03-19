# Czasomierze dla dodawania macierzy

 - Zdefiniuj klasę dla macierzy kwadratowej zawierającej liczby rzeczywiste. Należy umożliwić dostęp porzez referencję do poszczególnych elementów macierzy (do odczytu i zapisu). W klasie tej zdefiniuj statyczną operację mnożenia macierzy o takim samym rozmiarze (argumenty przekaż jako referencje do stałych macierzy).

 - Dalej w programie testowym stwórz macierze o rozmiarach odpowiednio 10×10, 100×100, 1000×1000 i 10000×10000.

 - Wypełnij je losowymi wartościami z zakrsu od 0.5 do 2.0.

 - Następnie podnieś do kwadratu każdą z tych macierzy mierząc czas wykonania tych operacji za pomocą obiektu `duration`.

 - Dla małych macierzy powtórz tą operację wielokrotnie, a potem zmierzony czas podziel przez tą wielokrotność. 

 - Do pomiaru czasu urzyj czasomierzy opartych na zegarze `high_resolution_clock`.
