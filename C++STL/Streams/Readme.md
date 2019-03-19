# Inteligentne wskaźniki

Zdefiniuj klasę opakowującą plik tekstowy `line_reader`.

Obiekt takiej klasy ma przetrzymywać wskaźnik/referencję do strumienia plikowego `ifstream`.

Zadaniem obiektów tej klasy będzie czytanie z pliku wiersz po wierszu.

Gdy strumień nie będzie już mógł odczytać następnej linii (koniec pliku) należy zgłosić wyjątek `ios_base::failure`.

Klasa ta nie powinna zamykać strumienia w destruktorze.

W programie testowym stwórz sprytny wskaźnik `shared_ptr`, który zamknie plik w momencie, 
gdy ostatni sprytny wskaźnik na ten zasób będzie likwidowany.
