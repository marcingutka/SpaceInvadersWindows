//---------------------------------------------------------------------------

#ifndef graH
#define graH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class Tgra_v1 : public TForm
{
__published:	// IDE-managed Components
        TShape *tlo;
        TImage *ship;
        TImage *bullet;
        TImage *enemy1;
        TTimer *t_enemy1;
        TTimer *t_e_bullet1;
        TImage *e_bullet1;
        TTimer *t_bullet;
        TTimer *t_ship_left;
        TTimer *t_ship_right;
        TTimer *ogolny;
        TButton *Koniec;
        TImage *ship_down;
        TImage *ship_up;
        TImage *enemy2;
        TImage *enemy3;
        TImage *enemy4;
        TImage *enemy5;
        TImage *e_bullet2;
        TImage *e_bullet3;
        TImage *e_bullet4;
        TImage *e_bullet5;
        TTimer *t_e_bullet2;
        TTimer *t_e_bullet3;
        TTimer *t_e_bullet4;
        TTimer *t_e_bullet5;
        void __fastcall t_enemy1Timer(TObject *Sender);
        void __fastcall t_e_bullet1Timer(TObject *Sender);
        void __fastcall t_bulletTimer(TObject *Sender);
        void __fastcall t_ship_leftTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall t_ship_rightTimer(TObject *Sender);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall ogolnyTimer(TObject *Sender);
        void __fastcall KoniecClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall t_e_bullet2Timer(TObject *Sender);
        void __fastcall t_e_bullet3Timer(TObject *Sender);
        void __fastcall t_e_bullet4Timer(TObject *Sender);
        void __fastcall t_e_bullet5Timer(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall Tgra_v1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tgra_v1 *gra_v1;
//---------------------------------------------------------------------------
#endif
