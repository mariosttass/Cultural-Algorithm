//---------------------------------------------------------------------------

#ifndef ViewH
#define ViewH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TViewForm : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TPanel *Panel2;
        TLabel *LabelPop;
        TLabel *LabelGen;
        TLabel *LabelBS;
        TPanel *PanelPop;
        TPanel *PanelGen;
        TPanel *PanelBS;
        TLabel *Label1;
        TLabel *Labelfunc;
        TLabel *Labelmrate;
        TPanel *PanelBITS;
        TPanel *Panelfunc;
        TPanel *Panelmrate;
        TLabel *LabelVar;
        TPanel *PanelVar;
        TLabel *LabelHC;
        TPanel *PanelHC;
        TLabel *LabelSV;
        TPanel *PanelSV;
        TLabel *LabelBeliefS;
        TStringGrid *Table;
        TLabel *Label2;
        TLabel *Label3;
        TButton *Backbutton;
        TButton *Exitbutton;
        TButton *Openfilebutton;
        TLabel *LabelBel;
        TLabel *LabelTime;
        TPanel *PanelTime;
        void __fastcall BackbuttonClick(TObject *Sender);
        void __fastcall ExitbuttonClick(TObject *Sender);
        void __fastcall OpenfilebuttonClick(TObject *Sender);
        

private:	// User declarations
public:		// User declarations
        __fastcall TViewForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TViewForm *ViewForm;
//---------------------------------------------------------------------------
#endif
