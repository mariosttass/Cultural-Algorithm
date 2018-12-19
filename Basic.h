//---------------------------------------------------------------------------

#ifndef BasicH
#define BasicH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TBasicForm : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        TComboBox *Generations;
        TComboBox *Beliefspace;
        TComboBox *Bits;
        TComboBox *Problem;
        TComboBox *Mutation;
        TComboBox *Variation;
        TCheckBox *Savefile;
        TCheckBox *Hillclimb;
        TButton *Run;
        TButton *Exit;
        TLabel *Label3;
        TComboBox *Population;
        TEdit *EditName;
        TLabel *Label8;
        void __fastcall RunClick(TObject *Sender);
        void __fastcall ExitClick(TObject *Sender);
        void __fastcall SavefileClick(TObject *Sender);
       


private:	// User declarations
public:		// User declarations
        __fastcall TBasicForm(TComponent* Owner);

};
//---------------------------------------------------------------------------
extern PACKAGE TBasicForm *BasicForm;
//---------------------------------------------------------------------------
#endif
