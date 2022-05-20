//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
AnsiString nazwapliku="";
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N1Click(TObject *Sender)
{
    if (OpenDialog1->Execute())
    {
        try
        {
        TRESC->Lines->LoadFromFile(OpenDialog1->FileName);
        nazwapliku = OpenDialog1->FileName;
        }
        catch (...)
        {
        ShowMessage("B³¹d otwarcia pliku. Upewnij siê, ¿e plik istnieje na dysku.");
        }}}
//---------------------------------------------------------------------------
void __fastcall TForm1::Zapiszjako1Click(TObject *Sender)
{
    if (SaveDialog1->Execute())
    {
        try
        {
        TRESC->Lines->SaveToFile(SaveDialog1->FileName);
        nazwapliku = SaveDialog1->FileName;
        }
        catch (...)
        {
        ShowMessage("Zapis zakonczyl sie niepowodzeniem.");
        }}}
//---------------------------------------------------------------------------
void __fastcall TForm1::Zapisz1Click(TObject *Sender)
{
      if (nazwapliku!="")
      {
      TRESC->Lines->SaveToFile(nazwapliku);
      }
      else
      {
      Form1->Zapiszjako1Click(MainMenu1);
      }}
//---------------------------------------------------------------------------
void __fastcall TForm1::Nowy1Click(TObject *Sender)
{
  if (Application->MessageBox("Czy na pewno utworzyc nowy plik", "Potwierz",
  MB_YESNOCANCEL | MB_ICONQUESTION)== IDYES)
  {
        TRESC->Lines->Clear();
        nazwapliku="";
  }}
//---------------------------------------------------------------------------
void __fastcall TForm1::TRESCKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if (Shift.Contains(ssCtrl))
        {
         if  ((Key == 's') || (Key == 'S'))
         {
            Form1-> Zapisz1Click(MainMenu1);
         }}}
//---------------------------------------------------------------------------
void __fastcall TForm1::Zakoncz1Click(TObject *Sender)
{
         if (Application->MessageBox("Czy na pewno zakonczyc program?", "Potwierdz",
  MB_YESNO | MB_ICONQUESTION)== IDYES)
  {
        Application->Terminate();
  }}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
          if (Application->MessageBox("Czy na pewno zakonczyc program?", "Potwierdz",
  MB_YESNO | MB_ICONQUESTION)== IDNO)
  {
     Action=caNone;
  } }
//---------------------------------------------------------------------------
void __fastcall TForm1::Wytnij1Click(TObject *Sender)
{
        TRESC->CutToClipboard();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Kopiuj1Click(TObject *Sender)
{
        TRESC-> CopyToClipboard();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Wklej1Click(TObject *Sender)
{
        TRESC -> PasteFromClipboard();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Zawijaniewierszy1Click(TObject *Sender)
{
        if (Zawijaniewierszy1->Checked==true)
        {
                Zawijaniewierszy1->Checked=false;
                TRESC->WordWrap=false;
                TRESC->ScrollBars = ssBoth;
        }
       else
       {
       Zawijaniewierszy1->Checked=true;
       TRESC->WordWrap=true;
       TRESC->ScrollBars=ssVertical;
       }}
//---------------------------------------------------------------------------
void __fastcall TForm1::CZcionka1Click(TObject *Sender)
{
        if (FontDialog1->Execute())
        {
        //kroj
        TRESC->Font->Name=FontDialog1->Font->Name;

        //kolor
        TRESC->Font->Color=FontDialog1->Font->Color;

        //rozmiar
        TRESC->Font->Size=FontDialog1->Font->Size;

        //styl
        TRESC->Font->Style=FontDialog1->Font->Style;
}}
//---------------------------------------------------------------------------
void __fastcall TForm1::Oprogramie1Click(TObject *Sender)
{
       Form2->ShowModal ();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Zapraszamnabloga1Click(TObject *Sender)
{
        ShellExecute(NULL, "open", "https://miroslawzelent.pl", NULL, NULL, SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------

