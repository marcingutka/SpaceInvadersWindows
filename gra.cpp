//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//#Windows.h

#include "gra.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tgra_v1 *gra_v1;

int y_enemy = 10; int y_e_bullet = 40;
int y_bullet = -40; int x_ship = 20;
int i = 0;
int interval_e_bullet=150;
int interval_enemy=1000;
int a1=0; int a2=0; int a3=0; int a4=0; int a5=0;

bool traf_enemy(TImage *naboj, TImage *przec)
{
     if ((przec->Left >= naboj->Left && przec->Left <= naboj->Left + naboj->Width && przec->Top +przec->Height >= naboj->Top) ||
     (przec->Left <= naboj->Left && przec->Left + przec->Width >= naboj->Left+naboj->Width && przec->Top +przec->Height >= naboj->Top) ||
     (przec->Left+przec->Width >= naboj->Left && przec->Left + przec->Width <= naboj->Left+naboj->Width && przec->Top +przec->Height >= naboj->Top))
     {
        return true;
     }
     else return false;
}

bool traf_gracz(TImage *poc, TImage *statek, TImage *pstatek1)
{
     if ((statek->Left >= poc->Left && statek->Left <= poc->Left+poc->Width && statek->Top <= poc->Top+poc->Height) ||
     (statek->Left <= poc->Left && statek->Left+statek->Width >= poc->Left+poc->Width && statek->Top <= poc->Top+poc->Height) ||
     (statek->Left+statek->Width >= poc->Left && statek->Left+statek->Width <= poc->Left+poc->Width && statek->Top <= poc->Top+poc->Height) ||

     (pstatek1->Top+pstatek1->Height-20 >= statek->Top))


     {
        return true;
     }
     else return false;
}

//---------------------------------------------------------------------------
__fastcall Tgra_v1::Tgra_v1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Tgra_v1::t_enemy1Timer(TObject *Sender)
{
        t_enemy1->Interval=interval_enemy;

        if (enemy1->Visible==true) enemy1->Top +=y_enemy;
        if (enemy2->Visible==true) enemy2->Top +=y_enemy;
        if (enemy3->Visible==true)enemy3->Top +=y_enemy;
        if (enemy4->Visible==true)enemy4->Top +=y_enemy;
        if (enemy5->Visible==true)enemy5->Top +=y_enemy;
}
//---------------------------------------------------------------------------

void __fastcall Tgra_v1::t_e_bullet1Timer(TObject *Sender)
{
        if (enemy1->Visible==true)
        {
                t_e_bullet1->Interval=interval_e_bullet;
                e_bullet1->Top += y_e_bullet;
                if (e_bullet1->Top+e_bullet1->Height >= tlo->Height)
        {
                        if (a1>0) e_bullet1->Top = enemy1->Top+enemy1->Height+10;
                        a1++;
                        if (a1==2) a1=0;
        }
        }
        else
        {
                e_bullet1->Top += y_e_bullet;
                a1=0;
                if (e_bullet1->Top+e_bullet1->Height >= tlo->Height)
                {
                        e_bullet1->Left=2000;
                        t_e_bullet1->Enabled=false;
                }
        }


}
//---------------------------------------------------------------------------

void __fastcall Tgra_v1::t_bulletTimer(TObject *Sender)
{
        bullet->Visible=true;
        bullet->Top += y_bullet;
        if (bullet->Top <= 0-bullet->Height/2){
                t_bullet->Enabled=false;
                bullet->Visible=false;
        }
}
//---------------------------------------------------------------------------

void __fastcall Tgra_v1::t_ship_leftTimer(TObject *Sender)
{
        if (ship->Left >= ship->Width/2) ship->Left -= x_ship;
}
//---------------------------------------------------------------------------

void __fastcall Tgra_v1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
      if (Key==VK_LEFT) t_ship_left->Enabled=true;
      if (Key==VK_RIGHT) t_ship_right->Enabled=true;
      if (Key==VK_SPACE && bullet->Visible==false) {
        bullet->Left = ship->Left + ship->Width/2;
        bullet->Top = ship->Top - ship->Height/2;
        t_bullet->Enabled=true;
      }

}
//---------------------------------------------------------------------------

void __fastcall Tgra_v1::t_ship_rightTimer(TObject *Sender)
{
         if (ship->Left <= tlo->Width - (ship->Width*1.5)) ship->Left += x_ship;
}
//---------------------------------------------------------------------------

void __fastcall Tgra_v1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if (Key==VK_LEFT) t_ship_left->Enabled=false;
        if (Key==VK_RIGHT) t_ship_right->Enabled=false;
}
//---------------------------------------------------------------------------


void __fastcall Tgra_v1::ogolnyTimer(TObject *Sender)
{
        if (traf_enemy(bullet, enemy1) == true)
        {
            enemy1->Visible=false;
            enemy1->Left=2000;
            i++;
        }

        if (traf_enemy(bullet, enemy2) == true)
        {
            enemy2->Visible=false;
            enemy2->Left=2000;
            i++;
        }
        if (traf_enemy(bullet, enemy3) == true)
        {
            enemy3->Visible=false;
            enemy3->Left=2000;
            i++;
        }
        if (traf_enemy(bullet, enemy4) == true)
        {
            enemy4->Visible=false;
            enemy4->Left=2000;
            i++;
        }
        if (traf_enemy(bullet, enemy5) == true)
        {
            enemy5->Visible=false;
            enemy5->Left=2000;
            i++;
        }

        if (i==5)
            {
            Koniec->Caption="Zwyciêstwo! Zagraj jeszcze raz!";
            Koniec->Visible=true;
            t_e_bullet1->Enabled=false;
            t_e_bullet2->Enabled=false;
            t_e_bullet3->Enabled=false;
            t_e_bullet4->Enabled=false;
            t_e_bullet5->Enabled=false;
            }

        if (traf_gracz(e_bullet1, ship, enemy1) == true || traf_gracz(e_bullet2, ship, enemy2) == true || traf_gracz(e_bullet3, ship, enemy3) == true || traf_gracz(e_bullet4, ship, enemy4) == true || traf_gracz(e_bullet5, ship, enemy5) == true)
        {
            t_bullet->Enabled=false;
            t_e_bullet1->Enabled=false;
            t_e_bullet2->Enabled=false;
            t_e_bullet3->Enabled=false;
            t_e_bullet4->Enabled=false;
            t_e_bullet5->Enabled=false;
            ship->Picture= ship_down->Picture;
            if (bullet->Visible==false)
            {
            bullet->Visible=true;
            bullet->Left=2000;
            }

            t_enemy1->Enabled=false;
            enemy1->Visible=true;

            Koniec->Caption="Przegrana! Zagraj jeszcze raz!";
            Koniec->Visible=true;
        }
}
//---------------------------------------------------------------------------

void __fastcall Tgra_v1::KoniecClick(TObject *Sender)
{
         Koniec->Visible=false;
         ship->Left = 352;
         ship->Picture = ship_up->Picture;
         bullet->Left= -20;

         t_e_bullet1->Enabled=true;
         e_bullet1->Top = 56;
         e_bullet1->Left = 387;

         enemy1->Top=16;
         enemy1->Left=376;
         t_enemy1->Enabled=true;
         enemy1->Visible=true;

         t_e_bullet2->Enabled=true;
         e_bullet2->Top = 56;
         e_bullet2->Left = 243;

         enemy2->Top=16;
         enemy2->Left=232;
         enemy2->Visible=true;

         t_e_bullet3->Enabled=true;
         e_bullet3->Top = 56;
         e_bullet3->Left = 539;

         enemy3->Top=16;
         enemy3->Left=528;
         enemy3->Visible=true;

         t_e_bullet4->Enabled=true;
         e_bullet4->Top = 104;
         e_bullet4->Left = 315;

         enemy4->Top=64;
         enemy4->Left=304;
         enemy4->Visible=true;

         t_e_bullet5->Enabled=true;
         e_bullet5->Top = 104;
         e_bullet5->Left = 483;

         enemy5->Top=64;
         enemy5->Left=472;
         enemy5->Visible=true;

         i=0;
         bullet->Visible=false;
         bullet->Left=384;
         bullet->Top=352;


}
//---------------------------------------------------------------------------


void __fastcall Tgra_v1::FormCreate(TObject *Sender)
{
bullet->Left =-20;
}
//---------------------------------------------------------------------------

void __fastcall Tgra_v1::t_e_bullet2Timer(TObject *Sender)
{
         if (enemy2->Visible==true)
        {
                t_e_bullet2->Interval=interval_e_bullet;
                e_bullet2->Top += y_e_bullet;
                if (e_bullet2->Top+e_bullet2->Height >= tlo->Height)
        {
                        if (a2>0) e_bullet2->Top = enemy2->Top+enemy2->Height+10;
                        a2++;
                        if (a2==3) a2=0;
        }
        }
        else
        {
        e_bullet2->Top += y_e_bullet;
        a2=0;
        if (e_bullet2->Top+e_bullet2->Height >= tlo->Height)
        {
                e_bullet2->Left=2000;
                t_e_bullet2->Enabled=false;
        }
        }
}
//---------------------------------------------------------------------------

void __fastcall Tgra_v1::t_e_bullet3Timer(TObject *Sender)
{
if (enemy3->Visible==true)
        {
                t_e_bullet3->Interval=interval_e_bullet;
                e_bullet3->Top += y_e_bullet;
                if (e_bullet3->Top+e_bullet3->Height >= tlo->Height)
        {
                        if (a3>0) e_bullet3->Top = enemy3->Top+enemy3->Height+10;
                        a3++;
                        if (a3==5) a3=0;
        }
        }
        else
        {
        e_bullet3->Top += y_e_bullet;
        a3=0;
        if (e_bullet3->Top+e_bullet3->Height >= tlo->Height)
        {
                e_bullet3->Left=2000;
                t_e_bullet3->Enabled=false;
        }
        }
}
//---------------------------------------------------------------------------

void __fastcall Tgra_v1::t_e_bullet4Timer(TObject *Sender)
{
if (enemy4->Visible==true)
        {
                t_e_bullet4->Interval=interval_e_bullet;
                e_bullet4->Top += y_e_bullet;
                if (e_bullet4->Top+e_bullet4->Height >= tlo->Height)
        {
                        if (a4>0) e_bullet4->Top = enemy2->Top+enemy2->Height+10;
                        a4++;
                        if (a4==2) a4=0;
        }
        }
        else
        {
        e_bullet4->Top += y_e_bullet;
        a4=0;
        if (e_bullet4->Top+e_bullet4->Height >= tlo->Height)
        {
                e_bullet4->Left=2000;
                t_e_bullet4->Enabled=false;
        }
        }
}
//---------------------------------------------------------------------------

void __fastcall Tgra_v1::t_e_bullet5Timer(TObject *Sender)
{
if (enemy5->Visible==true)
        {
                t_e_bullet5->Interval=interval_e_bullet;
                e_bullet5->Top += y_e_bullet;
                if (e_bullet5->Top+e_bullet5->Height >= tlo->Height)
        {
                        if (a5>0) e_bullet5->Top = enemy5->Top+enemy5->Height+10;
                        a5++;
                        if (a5==4) a5=0;
        }
        }
        else
        {
        e_bullet5->Top += y_e_bullet;
        a5=0;
        if (e_bullet5->Top+e_bullet5->Height >= tlo->Height)
        {
                e_bullet5->Left=2000;
                t_e_bullet5->Enabled=false;
        }
        }
}
//---------------------------------------------------------------------------


