int risDaRaggiungere; //Indica il risultato a cui bisogna arrivare per vincere
char mossaGiocatore; //Indica il numero che ha inserito il giocatore durante la sua mossa
int mossaAppoggio; //Questa sarà la variabile d'appoggio per le mosse del giocatore
int numeroCorrente; //Indica il numero corrente a cui si è arrivati
int turno; // turno = 0 (giocatore 1) | turno = 1 (giocatore 2)
bool finito; //Variabile booleana che verrà utilizzata nei cicli
int cont; //Contatore che verrà utilizzato nei cicli

void setup()
{
  // put your setup code here, to run once:

  Serial.begin(9600);
  risDaRaggiungere = 0;
  numeroCorrente = 0;
  turno = 0;
  finito = false;
  cont = 0;
  mossaGiocatore = '0';
  mossaAppoggio = 0;
}

void loop()
{
  // put your main code here, to run repeatedly:
  ProvaNumeri();
}

void LetturaMossa() //Metodo che consente la lettura dell'input effettuato dal giocatore
{
  mossaGiocatore = Serial.readString().toInt();
  mossaAppoggio = mossaGiocatore;
}

void FaiMossa() //Permette al giocatore di fare la sua mossa
{
  while(!finito)
  {
    LetturaMossa();
    if (mossaAppoggio > 0 && mossaAppoggio < 7)
    {
      finito = true;
    }
  }
  finito = false;
  Serial.println(mossaAppoggio, DEC);  
  AzzeramentoMosseDelGiocatore();
}

void AggiungiMossaAlRisultato() //Aggiunge la mossa appena fatta al risultato corrente
{
  numeroCorrente = numeroCorrente + mossaAppoggio;
  Serial.println(numeroCorrente);
}

void AzzeramentoMosseDelGiocatore() //Metodo che azzera la mossa appena fatta dal giocatore
{
  mossaGiocatore = '0';
  mossaAppoggio = 0;
}

void PassaTurno()
{
  if (turno == 0)
  {
    turno = 1;
  }
  else
  {
    turno = 0;
  }
}

void DeterminaChiVince() //Metodo che determina chi vince in base a chi ha eseguito l'ultima mossa 
{
  if (turno == 0 && numeroCorrente == risDaRaggiungere)
  {
    Serial.println("Vince il Giocatore 1");
  }
  else if (turno == 1 && numeroCorrente == risDaRaggiungere)
  {
    Serial.println("Vince il Giocatore 2");
  }
  else if (turno == 0 && numeroCorrente > risDaRaggiungere)
  {
    Serial.println("Vince il Giocatore 2");
  }
  else if (turno == 1 && numeroCorrente > risDaRaggiungere)
  {
  Serial.println("Vince il Giocatore 1"); 
  }
}

void TerminaPartita() //Metodo che termina la partita e riazzera le mosse
{
  risDaRaggiungere = 0;
  numeroCorrente = 0;
  turno = 0;
}
