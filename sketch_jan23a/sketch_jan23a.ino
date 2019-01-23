int totale; //Indica il risultato a cui bisogna arrivare per vincere
int mossaGiocatore; //Indica il numero che ha inserito il giocatore durante la sua mossa
char numeroCorrente; //Indica il numero corrente a cui si è arrivati
int turno; // turno = 0 (giocatore 1) | turno = 1 (giocatore 2)
char istruzioni //Le istruzioni che verranno visualizzate nel monitor seriale

void setup() 
{
  // put your setup code here, to run once:

  Serial.begin(9600);
  totale = 0;
  mossaGiocatore = 0;
  turno = 0;
}

void loop() 
{ 
  // put your main code here, to run repeatedly:
  Serial.print("ciao");
  /*void PassaTurno()
  {
    if (turno == 0)
    {
      turno = 1;
      istruzioni = "Tocca al Giocatore 2"
    }
    else
    {
      turno = 0;
      istruzioni = "Tocca al Giocatore 1";
    }
    Serial.println(istruzioni);
  }
  void AggiungiMossaAlRisultato() //Aggiunge la mossa appena fatta al risultato corrente
  {
    numeroCorrente = numeroCorrente + mossaGiocatore;
    Serial.println(numeroCorrente);
  }

  void FaiMossa() //Permette al giocatore di fare la sua mossa
  {
    mossaGiocatore = Serial.read();
  }*/
}
