#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Compartimento.h"

void FLVaziaRocha(Compartimento* LRocha) {
    LRocha->first = InicioArranjo;
    LRocha->last = LRocha->first;
}   
int LEhVaziaRocha(Compartimento* LRocha) {
    return LRocha->last == LRocha->first;
}
int LInsereRocha(Compartimento* LRocha, RochaMineral x) {
    if (LRocha->last == MaxTam) {
        return 0;
    }
    
}
void LImprimeRocha(Compartimento* LRocha) {

}