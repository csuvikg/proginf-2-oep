#include "enor.h"
#include <iostream>

using namespace std;

void vadaszatEnor::next() {
    x.read(sx, dx);
    if (sx == norm) {
        akt.id = dx.id;
        akt.suly = 0;
        akt.medve = false;
        for (unsigned i = 0; i < dx.fajta.size(); ++i) {
            if (dx.fajta[i] != "medve") {
                continue;
            } else if (akt.medve && dx.fajta[i] == "medve") {
                if (dx.suly[i] > akt.suly) {
                    akt.suly = dx.suly[i];
                }
            } else {
                akt.medve = true;
                akt.suly = dx.suly[i];
            }
        }
    }
}

void vadaszEnor::next() {
    vege = v.end();

    if (!vege) {
        cur.id = v.current().id;
        cur.lott = false;

        while (!v.end() && cur.id == v.current().id) {
            cur.lott = cur.lott || v.current().medve;
            v.next();
        }
    }
}
