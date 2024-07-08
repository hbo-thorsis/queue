#include <iostream>
#include <queue>
#include <string>

// In Schritt 6 wird folgendes eingeführt:
// a) Abfragemethode 3 für Pointer Queue
// b) Erweiterung des Hauptprogramms, welches die Abfragefunktion 3 nutzt


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
            out_string = queue_string.front();
            queue_string.pop();            
        }
        void receive_method2( std::string** out_string )
        {
            *out_string = queue_string.front();
            queue_string.pop();                 
        }
        std::string* receive_method3()
        {
            std::string* out_string = queue_string.front();
            queue_string.pop();    
            return out_string;               
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

    std::string* out_string;
    out_string = greetings.receive_method3();
    std::cout << std::endl << "-------Methode 3--------" << std::endl << *out_string << std::endl;
    delete out_string;
    out_string = nullptr;
    // zu diskutieren
    // a) Methode, warum stürzt die nicht ab?
    
    return 0;
}