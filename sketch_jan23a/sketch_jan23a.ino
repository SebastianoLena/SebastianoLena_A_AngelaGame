int risDaRaggiungere; //Indica il risultato a cui bisogna arrivare per vincere
char risDaRaggiungere2; //Permette ai giocatori di inserire il risultato da raggiungere
char mossaGiocatore; //Indica il numero che ha inserito il giocatore durante la sua mossa
int mossaAppoggio1; //Questa sarà la variabile d'appoggio per le mosse del giocatore
int mossaAppoggio2; //Questa variabile verrà utilizzata per impedire di inserire i numeri che equivalgono alla faccia opposta del dado es: 1-6 2-5
int numeroCorrente; //Indica il numero corrente a cui si è arrivati
int turno; // turno = 0 (giocatore 1) | turno = 1 (giocatore 2)
int turnoIniziale; //Indica il turno con cui è cominciato l'ultima partita effettuata
bool finito; //Variabile booleana che verrà utilizzata nei cicli
int cont; //Contatore che verrà utilizzato nei cicli
int numTurni; //Variabile che terrà conto del numero dei turni della partita es: Gioc.2 fa la sua mossa e il turno aumenta di 1
String istruzioni; //Stringa che andrà a visualizzare nel monitor seriale le informazioni necessarie

void setup()
{
  // put your setup code here, to run once:

  Serial.begin(9600);
  risDaRaggiungere = 0;
  numeroCorrente = 0;
  turno = 0;
  turnoIniziale = 0;
  finito = false;
  cont = 0;
  mossaGiocatore = '7';
  mossaAppoggio1 = -1;
  mossaAppoggio2 = -1;
  numTurni = 0;
  istruzioni = "";
}

void loop()
{
  // put your main code here, to run repeatedly:
  ScegliRisDaRaggiungere();
  FaiMossa();
}

void ScegliRisDaRaggiungere()
{
  if (numTurni == 0)
  {
    Serial.println("SELEZIONA IL RISULTATO DA RAGGIUNGERE DA 30 A 99");
    while(!finito)
    {
     if (risDaRaggiungere >= 30 && risDaRaggiungere < 100)
      {
        finito = true;
      }
      else
      {
        risDaRaggiungere2 = Serial.readString().toInt();
        risDaRaggiungere = risDaRaggiungere2;
      }  
    }
    Serial.println("");
    Serial.print("Il risultato da raggiungere è: ");
    Serial.println(risDaRaggiungere);
    finito = false;
  }
}
void LetturaMossa() //Metodo che consente la lettura dell'input effettuato dal giocatore
{
  while (!finito)
  {
    mossaAppoggio2 = mossaAppoggio1;
    mossaGiocatore = Serial.readString().toInt();
    mossaAppoggio1 = mossaGiocatore;
    if (numTurni == 0 && mossaAppoggio1 >= 0  && mossaAppoggio1 < 7 && mossaAppoggio1 != mossaAppoggio2 && mossaAppoggio1 != (7 - mossaAppoggio2))
    {
     finito = true;
    }
    else if (mossaAppoggio1 > 0 && mossaAppoggio1 < 7 && mossaAppoggio1 != mossaAppoggio2 && mossaAppoggio1 != (7 - mossaAppoggio2))
    {
     finito = true;
    }
  }
  finito = false;
}

void FaiMossa() //Permette al giocatore di fare la sua mossa
{
  LetturaMossa();
  if (turno == 0)
  {
    istruzioni = "Mossa Giocatore 1: ";
  }
  else
  {
    istruzioni = "Mossa Giocatore 2: ";
  }
  Serial.print(istruzioni);
  Serial.println(mossaAppoggio1);
  AggiungiMossaAlRisultato();  
}

void AggiungiMossaAlRisultato() //Aggiunge la mossa appena fatta al risultato corrente
{
  numeroCorrente = numeroCorrente + mossaAppoggio1;
  istruzioni = "Numero Corrente: ";
  Serial.print(istruzioni);
  Serial.println(numeroCorrente);
  DeterminaChiVince();
  PassaTurno();
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

void CambiaTurnoIniziale() //Questo metodo decide chi dovrà fare la prima mossa nella prossima partita in base a chi ha eseguito per primo la sua mossa in quella precedente
{
  if (turnoIniziale == 0)
  {
    turnoIniziale = 1;
    Serial.println("Comincia Il Giocatore 2");
    turno = 0;
  }
  else
  {
    turnoIniziale = 0;
    Serial.println("Comincia Il Giocatore 1");
    turno = 1;
  }
}

void DeterminaChiVince() //Metodo che determina chi vince in base a chi ha eseguito l'ultima mossa 
{
  if (turno == 0 && numeroCorrente == risDaRaggiungere)
  {
    Serial.println("VINCE IL GIOCATORE 1");
    Serial.println("");
    TerminaPartita();
    CambiaTurnoIniziale();
    ScegliRisDaRaggiungere();
  }
  else if (turno == 1 && numeroCorrente == risDaRaggiungere)
  {
    Serial.println("VINCE IL GIOCATORE 2");
    Serial.println("");
    TerminaPartita();
    CambiaTurnoIniziale();
    ScegliRisDaRaggiungere();
  }
  else if (turno == 0 && numeroCorrente > risDaRaggiungere)
  {
    Serial.println("VINCE IL GIOCATORE 2");
    Serial.println("");
    TerminaPartita();
    CambiaTurnoIniziale();
    ScegliRisDaRaggiungere();
  }
  else if (turno == 1 && numeroCorrente > risDaRaggiungere)
  {
    Serial.println("VINCE IL GIOCATORE 1");
    Serial.println(""); 
    TerminaPartita();
    CambiaTurnoIniziale();
    ScegliRisDaRaggiungere();
  }
}

void TerminaPartita() //Metodo che termina la partita
{
  numTurni = 0;
  mossaAppoggio1 = -1;
  mossaAppoggio2 = -1;
  numeroCorrente = 0;
  risDaRaggiungere = 0;
}
