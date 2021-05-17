## Testy

### TUczen

| Test                                                          | Wynik testu                                                          |
| ------------------------------------------------------------- | -------------------------------------------------------------------- |
| `zarejestruj` używając loginu nie znajdującego się w systemie | Student znajduje się na liście studentów uczelni.                    |
| `zarejestruj` używając tego samego loginu                     | Pojawienie się wyjątku: _użytkownik o podanym loginie już istnieje_. |
| `zaloguj` używając loginu nie znajdującego się w systemie     | Pojawienie się wyjątku: _błąd autentykacji_.                         |
| `zaloguj` używając poprawnego loginu ale błędnego hasła       | Pojawienie się wyjątku: _błąd autentykacji_.                         |
| `zaloguj` używając poprawnego loginu i hasła                  | Użytkownik jest zalogowany.                                          |
| `zapisz` na wykład                                            | Student znajduje się na liście zapisanych na wykład.                 |

### TWykladowca

| Test                                     | Wynik testu                                                                                                                                 |
| ---------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------- |
| `zarejestruj` wykładowcę                 | Wykładowca znajduje się na liście wykładowców wydziału.                                                                                     |
| `dodajWyklad` zarejestrowanego studenta  | Wyklad znajduje się na liście prowadzonych wykładów.                                                                                        |
| `usunStudenta` zarejestrowanego studenta | <ol><li>Student nie znajduje się na liście studentów uczelni.</li><li>Student nie jest znajduje się na liście żadnego z wykładów.</li></ol> |
