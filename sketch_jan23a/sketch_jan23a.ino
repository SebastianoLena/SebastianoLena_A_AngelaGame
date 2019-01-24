int totale; //Indica il risultato a cui bisogna arrivare per vincere
char mossaGiocatore; //Indica il numero che ha inserito il giocatore durante la sua mossa
int numeroCorrente; //Indica il numero corrente a cui si è arrivati
int turno; // turno = 0 (giocatore 1) | turno = 1 (giocatore 2)
//char istruzioni; //Le istruzioni che verranno visualizzate nel monitor seriale
bool finito; //Variabile booleana che verrà utilizzata nei cicli
int cont; //Contatore che verrà utilizzato nei cicli

void setup()
{
  // put your setup code here, to run once:

  Serial.begin(9600);
  totale = 0;
  numeroCorrente = 0;
  turno = 0;
  finito = false;
  cont = 0;
  mossaGiocatore = '0';
}

void loop()
{
  // put your main code here, to run repeatedly:
  FaiMossa();
  delay(1000);
}

/*void DaiIStruzioni()
{
  Serial.print(istruzioni);
}*/

void PassaTurno()
{
  if (turno == 0)
  {
    turno = 1;
    //istruzioni = "Tocca al Giocatore 2";
  }
  else
  {
    turno = 0;
    //istruzioni = "Tocca al Giocatore 1";
  }
}
void AggiungiMossaAlRisultato() //Aggiunge la mossa appena fatta al risultato corrente
{
  numeroCorrente = numeroCorrente + mossaGiocatore;
  Serial.println(numeroCorrente);
}

void FaiMossa() //Permette al giocatore di fare la sua mossa
{
  while(!finito)
  {
    mossaGiocatore = Serial.read();
    if (mossaGiocatore > 0 && mossaGiocatore < 7) 
    {
      finito = true;
    }
  }
  finito = false;
  Serial.println(mossaGiocatore);
  mossaGiocatore = '0';
  
}

void TerminaPartita()
{
  totale = 0;
  numeroCorrente = 0;
  turno = 0;
}
