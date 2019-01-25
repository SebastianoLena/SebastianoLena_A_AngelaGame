int risDaRaggiungere; //Indica il risultato a cui bisogna arrivare per vincere
char mossaGiocatore; //Indica il numero che ha inserito il giocatore durante la sua mossa
int mossaAppoggio; //Questa sarà la variabile d'appoggio per le mosse del giocatore
int numeroCorrente; //Indica il numero corrente a cui si è arrivati
int turno; // turno = 0 (giocatore 1) | turno = 1 (giocatore 2)
bool finito; //Variabile booleana che verrà utilizzata nei cicli
int cont; //Contatore che verrà utilizzato nei cicli
int numTurni; //Variabile che terrà conto del numero dei turni della partita es: Gioc.2 fa la sua mossa e il turno aumenta di 1
String istruzioni; //Stringa che andrà a visualizzare nel monitor seriale le informazioni necessarie

void setup()
{
  // put your setup code here, to run once:

  Serial.begin(9600);
  risDaRaggiungere = 30;
  numeroCorrente = 0;
  turno = 0;
  finito = false;
  cont = 0;
  mossaGiocatore = '0';
  mossaAppoggio = 0;
  numTurni = 0;
  istruzioni = "";
}

void loop()
{
  // put your main code here, to run repeatedly:
  FaiMossa();
}

void LetturaMossa() //Metodo che consente la lettura dell'input effettuato dal giocatore
{
  while (!finito)
  {
    mossaGiocatore = Serial.readString().toInt();
    mossaAppoggio = mossaGiocatore;
    if (numTurni == 0 && mossaAppoggio >= 0 && mossaAppoggio < 7)
    {
     finito = true;
    }
    else if (mossaAppoggio > 0 && mossaAppoggio < 7)
    {
     finito = true;
    }
  }
  finito = false;
}

void FaiMossa() //Permette al giocatore di fare la sua mossa
{
  LetturaMossa();
  Serial.println(mossaAppoggio, DEC);
  AggiungiMossaAlRisultato();  
  AzzeramentoMosseDelGiocatore();
}

void AggiungiMossaAlRisultato() //Aggiunge la mossa appena fatta al risultato corrente
{
  numeroCorrente = numeroCorrente + mossaAppoggio;
  istruzioni = "Numero Corrente: " + numeroCorrente;
  Serial.println(numeroCorrente);
  DeterminaChiVince();
  PassaTurno();
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
  numTurni++;
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
  numTurni = 0;
}
