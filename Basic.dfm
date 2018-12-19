object BasicForm: TBasicForm
  Left = 615
  Top = 126
  Width = 532
  Height = 569
  Caption = 'Basic Form'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 104
    Top = 64
    Width = 50
    Height = 13
    Caption = 'Population'
  end
  object Label2: TLabel
    Left = 104
    Top = 112
    Width = 57
    Height = 13
    Caption = 'Generations'
  end
  object Label4: TLabel
    Left = 112
    Top = 208
    Width = 24
    Height = 13
    Caption = 'BITS'
  end
  object Label5: TLabel
    Left = 96
    Top = 256
    Width = 82
    Height = 13
    Caption = 'Function Problem'
  end
  object Label6: TLabel
    Left = 96
    Top = 304
    Width = 67
    Height = 13
    Caption = 'Mutation Rate'
  end
  object Label7: TLabel
    Left = 96
    Top = 352
    Width = 41
    Height = 13
    Caption = 'Variation'
  end
  object Label3: TLabel
    Left = 104
    Top = 160
    Width = 60
    Height = 13
    Caption = 'Belief Space'
  end
  object Label8: TLabel
    Left = 208
    Top = 416
    Width = 71
    Height = 20
    Caption = 'File Name'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Generations: TComboBox
    Left = 224
    Top = 104
    Width = 177
    Height = 21
    ItemHeight = 13
    TabOrder = 0
    Text = 'Generations'
    Items.Strings = (
      '10'
      '20'
      '50'
      '100'
      '200'
      '400'
      '600'
      '1000'
      '1200'
      '1500')
  end
  object Beliefspace: TComboBox
    Left = 224
    Top = 152
    Width = 177
    Height = 21
    ItemHeight = 13
    TabOrder = 1
    Text = 'Beliefspace'
    Items.Strings = (
      '5'
      '10'
      '20'
      '40')
  end
  object Bits: TComboBox
    Left = 224
    Top = 200
    Width = 177
    Height = 21
    ItemHeight = 13
    TabOrder = 2
    Text = 'Bits'
    Items.Strings = (
      '10'
      '12'
      '14'
      '16')
  end
  object Problem: TComboBox
    Left = 224
    Top = 248
    Width = 177
    Height = 21
    ItemHeight = 13
    TabOrder = 3
    Text = 'Problem'
    Items.Strings = (
      'ROSENBROCK'
      'RASTRIGIN'
      'SCHWEFEL'
      'PARALLELOGRAM')
  end
  object Mutation: TComboBox
    Left = 224
    Top = 296
    Width = 177
    Height = 21
    ItemHeight = 13
    TabOrder = 4
    Text = 'Mutation'
    Items.Strings = (
      '0.005'
      '0.008'
      '0.01'
      '0.02'
      '0.03'
      '0.04'
      '0.05'
      '0.07'
      '0.1')
  end
  object Variation: TComboBox
    Left = 176
    Top = 344
    Width = 273
    Height = 21
    ItemHeight = 13
    ParentShowHint = False
    ShowHint = False
    TabOrder = 5
    Items.Strings = (
      
        'Improve ONLY the best solution for each generation using Belief ' +
        'Space.'
      'Improve ALL solutions for each generation using Belief Space.'
      
        'Crossover every solution with the most near solution in Belief S' +
        'pace.')
  end
  object Savefile: TCheckBox
    Left = 88
    Top = 424
    Width = 97
    Height = 17
    Caption = 'Save File'
    TabOrder = 6
    OnClick = SavefileClick
  end
  object Hillclimb: TCheckBox
    Left = 88
    Top = 384
    Width = 97
    Height = 17
    Caption = 'Hill Climb'
    Checked = True
    State = cbChecked
    TabOrder = 7
  end
  object Run: TButton
    Left = 88
    Top = 472
    Width = 75
    Height = 25
    Caption = 'Run'
    TabOrder = 8
    OnClick = RunClick
  end
  object Exit: TButton
    Left = 376
    Top = 472
    Width = 75
    Height = 25
    Caption = 'Exit'
    TabOrder = 9
    OnClick = ExitClick
  end
  object Population: TComboBox
    Left = 224
    Top = 56
    Width = 177
    Height = 21
    ItemHeight = 13
    TabOrder = 10
    Text = 'Population'
    Items.Strings = (
      '10'
      '20'
      '50'
      '70'
      '100'
      '150'
      '200'
      '300')
  end
  object EditName: TEdit
    Left = 312
    Top = 416
    Width = 137
    Height = 21
    TabOrder = 11
    Text = 'results'
  end
end
