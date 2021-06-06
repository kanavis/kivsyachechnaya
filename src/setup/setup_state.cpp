/* Setup state */
#include "setup_state.h"
#include "storage/storage.h"


void load_state() {

}


void setup_state() {
    if (Storage::hasMagic()) {
        load_state();
    } else {
        init_state();
    }
}