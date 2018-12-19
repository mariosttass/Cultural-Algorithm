object ViewForm: TViewForm
  Left = 212
  Top = 175
  Width = 1291
  Height = 735
  Caption = 'View Form'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label2: TLabel
    Left = 24
    Top = 128
    Width = 574
    Height = 20
    Caption = 'BEST SOLUTION PER GENERATION AFTER CULTURAL ALGORITHM'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label3: TLabel
    Left = 744
    Top = 128
    Width = 128
    Height = 20
    Caption = 'BELIEF SPACE'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Panel1: TPanel
    Left = 24
    Top = 8
    Width = 1217
    Height = 105
    TabOrder = 0
    object LabelPop: TLabel
      Left = 16
      Top = 24
      Width = 50
      Height = 13
      Caption = 'Population'
    end
    object LabelGen: TLabel
      Left = 16
      Top = 48
      Width = 57
      Height = 13
      Caption = 'Generations'
    end
    object LabelBS: TLabel
      Left = 8
      Top = 72
      Width = 92
      Height = 13
      Caption = 'Size of BeliefSpace'
    end
    object Label1: TLabel
      Left = 264
      Top = 16
      Width = 76
      Height = 13
      Caption = 'Number of BITS'
    end
    object Labelfunc: TLabel
      Left = 264
      Top = 40
      Width = 82
      Height = 13
      Caption = 'Function Problem'
    end
    object Labelmrate: TLabel
      Left = 264
      Top = 64
      Width = 67
      Height = 13
      Caption = 'Mutation Rate'
    end
    object LabelVar: TLabel
      Left = 568
      Top = 16
      Width = 41
      Height = 13
      Caption = 'Variation'
    end
    object LabelHC: TLabel
      Left = 568
      Top = 45
      Width = 42
      Height = 13
      Caption = 'Hill Climb'
    end
    object LabelSV: TLabel
      Left = 560
      Top = 72
      Width = 56
      Height = 13
      Caption = 'Save to File'
    end
    object LabelTime: TLabel
      Left = 1048
      Top = 24
      Width = 85
      Height = 13
      Caption = 'Time of Execution'
    end
    object PanelPop: TPanel
      Left = 120
      Top = 16
      Width = 105
      Height = 25
      TabOrder = 0
    end
    object PanelGen: TPanel
      Left = 120
      Top = 40
      Width = 105
      Height = 25
      TabOrder = 1
    end
    object PanelBS: TPanel
      Left = 120
      Top = 64
      Width = 105
      Height = 25
      TabOrder = 2
    end
    object PanelBITS: TPanel
      Left = 384
      Top = 16
      Width = 137
      Height = 25
      TabOrder = 3
    end
    object Panelfunc: TPanel
      Left = 384
      Top = 40
      Width = 137
      Height = 25
      TabOrder = 4
    end
    object Panelmrate: TPanel
      Left = 384
      Top = 64
      Width = 137
      Height = 25
      TabOrder = 5
    end
    object PanelVar: TPanel
      Left = 632
      Top = 16
      Width = 369
      Height = 25
      TabOrder = 6
    end
    object PanelHC: TPanel
      Left = 648
      Top = 40
      Width = 113
      Height = 25
      TabOrder = 7
    end
    object PanelSV: TPanel
      Left = 648
      Top = 64
      Width = 113
      Height = 25
      TabOrder = 8
    end
    object PanelTime: TPanel
      Left = 1040
      Top = 64
      Width = 169
      Height = 33
      TabOrder = 9
    end
  end
  object Panel2: TPanel
    Left = 664
    Top = 152
    Width = 345
    Height = 485
    TabOrder = 1
    object LabelBeliefS: TLabel
      Left = 43
      Top = 32
      Width = 3
      Height = 13
    end
    object LabelBel: TLabel
      Left = 56
      Top = 208
      Width = 3
      Height = 13
    end
  end
  object Table: TStringGrid
    Left = 16
    Top = 152
    Width = 633
    Height = 553
    ColCount = 8
    FixedCols = 0
    RowCount = 8
    ScrollBars = ssHorizontal
    TabOrder = 2
    ColWidths = (
      64
      64
      64
      64
      64
      64
      64
      64)
  end
  object Backbutton: TButton
    Left = 824
    Top = 664
    Width = 75
    Height = 25
    Caption = 'Back'
    TabOrder = 3
    OnClick = BackbuttonClick
  end
  object Exitbutton: TButton
    Left = 936
    Top = 664
    Width = 75
    Height = 25
    Caption = 'Exit'
    TabOrder = 4
    OnClick = ExitbuttonClick
  end
  object Openfilebutton: TButton
    Left = 688
    Top = 664
    Width = 75
    Height = 25
    Caption = 'Open File'
    TabOrder = 5
    OnClick = OpenfilebuttonClick
  end
end
