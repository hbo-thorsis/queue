#include <iostream>
#include <queue>
#include <string>

// In Schritt 1 wird folgendes eingeführt:
// a) Beispielklasse mit einem Queue-Objekt und diversen Funktionen
class Greetings
{
    public:
        // Konstruktor
        Greetings( void ) 
        {
        }
        // Destruktor
        ~Greetings( void )
        {
        }
        // Eintrag in Queue hinzufügen
        void add(std::string str)
        {
        }
        // Einen Eintrag aus de Queue entfernen
        void remove()
        {
        }        
        // Alle Einträge auflisten
        void list()
        {
        }    
        // Abfragen der Queue
        void receive_method1( std::string* out_string )
        {
        }
        void receive_method2( std::string** out_string )
        {
        }
        std::string* receive_method3()
        {
        }

    private:
        // Schnittstellenspeicher
        std::queue<std::string*> queue_string;

};

int main(void){
    return 0;
}