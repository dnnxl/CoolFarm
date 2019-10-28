#include "hilooveja.h"

HiloOveja::HiloOveja()
{

}

void HiloOveja::run()
{
    while(true)
    {
        if(true)
        {

        }
        else if(this->Pausa == true)
        {
            // Pausa no realiza nada.
        }
        else
        {
            this->Pausa = true; // Pausa la máquina.
            continue;
        }
        sleep(this->velocidad);
    }
}
