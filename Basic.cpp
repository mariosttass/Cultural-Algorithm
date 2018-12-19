//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Basic.h"
#include "Functions.h"
#include "View.h"
#include "VisualFunctions.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TBasicForm *BasicForm;
//---------------------------------------------------------------------------
/* Στην Παρακάτω συνάρτηση Αρχικοποιούμε τα αντικείμενα(Objects) που χρησιμοιούμε
 στην Βασική Φόρμα της εφαρμογής.
*/
__fastcall TBasicForm::TBasicForm(TComponent* Owner)
        : TForm(Owner)
{

    Population->ItemIndex=0;
    Generations->ItemIndex=0;
    Beliefspace->ItemIndex=0;
    Bits->ItemIndex=0;
    Problem->ItemIndex=0;
    Mutation->ItemIndex=2;
    Variation->ItemIndex=0;
    Hillclimb->Checked=true;
    EditName->Visible=false;
    Label8->Visible=false;

}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
/* Η παρακάτω συνάρτηση καλείται όταν κάνουμε κλίκ το κουμπί Run.
Δεν επιστρέφει τίποτα και δέχεται σαω όρισμα τον δείκτη του αντικειμένου.
Σε αυτήν την συνάρτηση μετράμε τον χρόνο εκτέλεσης του προγράμματος, 
κάνουμε τους βασικούς ελέγχους για τις τιμές που πληκτρολογεί ο 
χρήστης στα πεδία ή όταν δεν υπάρχουν καθόλου τιμές στα πεδία.
Ακόμη σε αυτην την συναρτηση καλείται ο βασικός αλγόριθμος, γίνεται η 
αρχικοποίηση των τιμών της δεύτερης φόρμας καθώς και 
η εμφάνιση της.                                                                      
*/
void __fastcall TBasicForm::RunClick(TObject *Sender)
{
        float a;                                                                                 
        int b;
        int start_time, end_time;
        //Έναρξή της χρονομέτρησης του αλγορίθμου.
        start_time = GetTickCount();

		// Η συνάρτηση TryStrToFloat μετατρέπει μια συμβολοσειρά σε πραγματικό αριθμό.
        if(!TryStrToFloat(Mutation->Text.c_str(),a))
        { 
                ShowMessage("You must enter numerical characters");
                if(a==0)
                        ShowMessage("You can't set 0 for Mutation Rate");
                Mutation->SetFocus();
                return;
         }
         else if(!TryStrToInt(Population->Text.c_str(),b) || b<10)
         {
                ShowMessage("You must set only integer number in Population Field and bigger than 10");

                Mutation->SetFocus();
                return;
         }
         else if(!TryStrToInt(Generations->Text.c_str(),b) || b<10)
         {
                ShowMessage("You must set only integer number in Generation Field and bigger than 10");
                Mutation->SetFocus();
                return;
         }
          else if(!TryStrToInt(Beliefspace->Text.c_str(),b) || b<5)
         {
                ShowMessage("You must set only integer number in Belief Space Field and bigger than 5");
                Mutation->SetFocus();
                return;
         }
          else if(!TryStrToInt(Bits->Text.c_str(),b) || b<10)
         {
                ShowMessage("You must set only integer number in BITS Field and bigger than 10");
                Mutation->SetFocus();
                return;
         }

        int B=BasicForm->Beliefspace->Text.ToInt();
		/* Αρχικοποιούμε το πάνελ στο οποίο βλέπουμε τις τιμές του
		χώρου μνήμης έτσι ώστε κάθε φορά που τρέχουμε το πρόγραμμα
		το πάνελ να είναι άδειο και να μην περιέχει σκουπίδια*/
        for(int i=0; i<B; i++)
                ViewForm->Panel2->DoubleBuffered=true; 
                ViewForm->LabelBeliefS->Update();
        // Αρχικοποιήση των τιμών την αντικειμένων της δεύτερης φόρμας.
        initialize();
		// Εκτέλεση του Βασικού Αλγορίθμου.
        algorithm();
		
		// Εμφάνιση της View φόρμας.
        ViewForm->Show();
        BasicForm->Hide();
		// Έλεγχος για αν έχουμε επιλέξει να σώσουμε τα αποτελέσματα του αλγορίθμου.
        if(Savefile->Checked==false)
                ViewForm->Openfilebutton->Enabled=false;
        //Τέλος της χρονομέτρησης του αλγορίθμου.
        end_time = GetTickCount() - start_time;
        ViewForm->PanelTime->Caption = FloatToStr(end_time / 1000.0) + "sec";

}
//---------------------------------------------------------------------------

/* Η παρακάτω συνάρτηση καλείται όταν κανούμε κλίκ στο κουμπί Έξοδος(Exit)
και η εφαρμογή τερματίζεται. */

void __fastcall TBasicForm::ExitClick(TObject *Sender)
{
        BasicForm->Close();
}
//---------------------------------------------------------------------------

/*Η παρακάτω συνάρτηση εκτελείται όταν κλικάρουμε το αντικείμενο Save file,
και στην περίπτωση που το έχουμε κλικάρει μας εμφάνίζει τα αντικέιμενα για 
να ονοματίσουμε το αρχείο στο οποίο θέλουμε να σώσουμε τα αποτελέσματα του 
αλγορίθμου.
*/
void __fastcall TBasicForm::SavefileClick(TObject *Sender)
{
                if(Savefile->Checked==true)
                {
                        EditName->Visible=true;
                        Label8->Visible=true;
                }
                else
                {
                  EditName->Visible=false;
                  Label8->Visible=false;
                }

}
//---------------------------------------------------------------------------


