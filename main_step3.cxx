#include <iostream>
#include <queue>
#include <string>

// In Schritt 3 wird folgendes eingeführt:
// a) Remove-Funktion
// b) Erweiterung des Hauptprogramms, welches die Remove Funktion nutzt


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
            while(!queue_string.empty()) {
                delete queue_string.front();
                queue_string.pop();
            }                  
        }
        // Eintrag in Queue hinzufügen
        void add(std::string str)
        {
            std::string* pstr = new std::string(str);
            queue_string.push(pstr);            
        }
        // Einen Eintrag aus de Queue entfernen
        void remove()
        {
            if(!queue_string.empty()) {
                delete queue_string.front();
                queue_string.pop();
            }                 
        }        

        // Alle Einträge auflisten
        void list()
        {
            std::queue<std::string*> copy = queue_string;
            std::cout << std::endl << "---------------" << std::endl;
            while (!copy.empty()) {
                std::cout << *copy.front() << std::endl;
                copy.pop();
            }            
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
    Greetings greetings;
    // Pointer Queue füllen
    greetings.add("Hallo");
    greetings.add("Guten Tag");
    greetings.add("Guten Abend");
    greetings.add("Gute Nacht");
    greetings.add("Gute Auf Wiedersehen");
    greetings.list();
    greetings.remove();
    greetings.list();


    return 0;
}