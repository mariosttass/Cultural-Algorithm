#include <vcl.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include "Basic.h"
#include "View.h"
#include "Functions.h"

/*Η παρακάτω συνάρτηση καλείται για να αρχικοποιήση τις στήλες
που εμφανίζονται στον πίνακα της φόρμας των αποτελεσμάτων. */
void iniTable()
{
       // ViewForm->Table->ColCount=8;
        ViewForm->Table->RowCount=BasicForm->Generations->Text.ToInt()+1;
         ViewForm->Table->Cells[0][0]="Generations";
         ViewForm->Table->Cells[1][0]="BinaryGeno0";
         ViewForm->Table->Cells[2][0]="BinaryGeno1";
         ViewForm->Table->Cells[3][0]="Geno0";
         ViewForm->Table->Cells[4][0]="Geno1";
         ViewForm->Table->Cells[5][0]="Pheno0";
         ViewForm->Table->Cells[6][0]="Pheno1";
         ViewForm->Table->Cells[7][0]="Fitness";

         ViewForm->Table->ColWidths[0]=50;
         ViewForm->Table->ColWidths[1]=70;
         ViewForm->Table->ColWidths[2]=70;
         ViewForm->Table->ColWidths[3]=40;
         ViewForm->Table->ColWidths[4]=40;
         ViewForm->Table->ColWidths[5]=110;
         ViewForm->Table->ColWidths[6]=110;
         ViewForm->Table->ColWidths[7]=110;


}


/*Η παρακάτω συνάρτηση καλείται για να αρχικοποιήση τις τιμές 
που ο χρήστής εισήγαγε στην βασική φόρμα όσον αναφορά τα πεδία των
παραμέτρων του αλγορίθμου . */
void initialize()
{

        ViewForm->PanelPop->Caption=BasicForm->Population->Text.ToInt();
        ViewForm->PanelGen->Caption=BasicForm->Generations->Text.ToInt();
        ViewForm->PanelBS->Caption=BasicForm->Beliefspace->Text.ToInt();
        ViewForm->PanelBITS->Caption=BasicForm->Bits->Text.ToInt();

        ViewForm->Panelfunc->Caption=BasicForm->Problem->Text;

       ViewForm->Panelmrate->Caption=BasicForm->Mutation->Text.ToDouble();

       ViewForm->PanelVar->Caption=BasicForm->Variation->Text;

       if(BasicForm->Hillclimb->Checked==true)
                ViewForm->PanelHC->Caption="true";
       else
                ViewForm->PanelHC->Caption="false";

      if(BasicForm->Savefile->Checked==true)
                ViewForm->PanelSV->Caption="true";
       else
                ViewForm->PanelSV->Caption="false";

      iniTable();

}

/*Η παρακάτω συνάρτηση καλείται για να καθαρίσει τα δεδομένα του
χώρου μνήμης, κάνει ενεργό το κουμπί ανοιγμα αρχείου και καλεί την 
συνάρτηση cleanFlagBS η οποία ειναι αυτή που αρχικοποιεί την μετάβλητη 
 flagBS. */
void cleandata()
{

        ViewForm->LabelBeliefS->Caption=" ";
        ViewForm->Openfilebutton->Enabled=true;
        cleanFlagBS();
}



