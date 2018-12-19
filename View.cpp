//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "View.h"
#include "Functions.h"
#include "VisualFunctions.h"
#include "Basic.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TViewForm *ViewForm;
//---------------------------------------------------------------------------
__fastcall TViewForm::TViewForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------





//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
/* Η παρακάτω συνάρτηση καλείται όταν πατήσουμε το κουμπί πίσω.
Καθαρίζουμε τον χώρο όπου εμφανίζεται ο χώρος μνήμης,
κλείνουμε την φορμά, και επιστρέφουμε στην βασική φόρμα.*/
void __fastcall TViewForm::BackbuttonClick(TObject *Sender)
{
        int B=BasicForm->Beliefspace->Text.ToInt();
        for(int i=0; i<B; i++)
                ViewForm->Panel2->DoubleBuffered=true;
                ViewForm->LabelBeliefS->Update();
        ViewForm->Close();
        cleandata();
        BasicForm->Show();

}
//---------------------------------------------------------------------------

/* Η παρακάτω συνάρτηση καλείται όταν πατήσουμε το κουμπί έξοδος.
Κλείνουμε εντελώς την εφαρμογή.*/
void __fastcall TViewForm::ExitbuttonClick(TObject *Sender)
{
        exit(0);        
}
//---------------------------------------------------------------------------
/* Η παρακάτω συνάρτηση καλείται όταν πατήσουμε το κουμπί άνοιγμα του αρχείου.
Ανοίγουμε το αρχείο που επιλέξαμε να σώσουμε τα αποτελέσματα της εκτέλεσης του αλγορίθμου.*/
void __fastcall TViewForm::OpenfilebuttonClick(TObject *Sender)
{
                if(BasicForm->EditName->Text!="")
                {
                    String name=BasicForm->EditName->Text + ".txt";
                    ShellExecute(0, "open", name.c_str(), NULL, NULL, SW_SHOWNORMAL);
                }
                else
                        ShellExecute(0, "open", "results.txt", NULL, NULL, SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------


