#pragma once
#include "UIBase.h"
namespace CellularNetworkDemonstration {

    class ViewBase :
        public UIBase {
    public:
        ViewBase(SDL_Renderer *renderer, int viewCode)
            :UIBase(renderer, 800, 450), m_iViewCode(viewCode) {
        }
        virtual ~ViewBase() {
        }
        int getViewCode() const {
            return this->m_iViewCode;
        }
    private:
        const int m_iViewCode;
    };

}

