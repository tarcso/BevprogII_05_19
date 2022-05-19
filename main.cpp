#include "gordmenu.hpp"
#include "menuelem.hpp"
#include "szambeall.hpp"
#include "pushbutton.hpp"
#include "Window.hpp"
#include "textbox.hpp"
#include "szovegszerk.hpp"
#include <vector>
#include <fstream>
#include <functional>
#include <vector>

using namespace genv;

const int XX = 500;
const int YY = 400;

enum class sktype
{
    intelligencia,
    kitartas,
    memoria,
    erdeklodes
};

struct Skillek
{
    private:
        int ossz, marad;
        std::vector<int> skills;

    public:
        Skillek(int max) : ossz(max)
        {
            skills = {1, 1, 1, 1};
        }

        int getOssz() const
        {
            return ossz;
        }

        void update(int intel, int kitart, int memo, int erdek)
        {
            skills[int(sktype::intelligencia)] = intel;
            skills[int(sktype::kitartas)] = kitart;
            skills[int(sktype::memoria)] = memo;
            skills[int(sktype::erdeklodes)] = erdek;
            marad = ossz-intel-kitart-memo-erdek;
        }

        int getmarad() const
        {
            return marad;
        }
};

class Pelda: public Window
{
    private:
        Szambeall* sz1;
        Szambeall* sz2;
        Szambeall* sz3;
        Szambeall* sz4;
        SzovegSzerk* szov;
        GordMenu* g;
        textBox* t;
        textBox* t1;
        textBox* t2;
        textBox* t3;
        textBox* t4;
        textBox* t5;
        Skillek* s;
       

    public:
       Pelda()
        {
            screenx = XX;
            screeny = YY;
            s = new Skillek(25);
            t = new textBox(this, 30, 25, 100, 20, "Név");
            szov = new SzovegSzerk(this, 30, 50, 250, 40);
            sz1 = new Szambeall(this, 130, 100, 70, 30, 1, 10);
            sz2 = new Szambeall(this, 130, 150, 70, 30, 1, 10);
            sz3 = new Szambeall(this, 130, 200, 70, 30, 1, 10);
            sz4 = new Szambeall(this, 130, 250, 70, 30, 1, 10);
            t1 = new textBox(this, 30, 100, 95, 30, "intelligencia");
            t2 = new textBox(this, 30, 150, 95, 30, "kitartás");
            t3 = new textBox(this, 30, 200, 95, 30, "memória");
            t4 = new textBox(this, 30, 250, 95, 30, "érdeklődés");
            t5 = new textBox(this, 300, 175, 190, 30, "Szabad skillpont: " + std::to_string(s->getmarad()));
        }

        void esemeny(const std::string& ki_mondta)
        {
            if(ki_mondta == "update")
            {
                s->update(sz1->allapot(), sz2->allapot(), sz3->allapot(), sz4->allapot());
                t5->setText("Szabad skillpont: " + std::to_string(s->getmarad()));
            }
        }
};

int main()
{
    gout.open(XX, YY);
    gout.load_font("LiberationSans-Regular.ttf");
    Pelda* p = new Pelda;
    p->event_loop();
    return 0;
}
