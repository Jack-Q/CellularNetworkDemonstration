#pragma once
#include "ViewBase.h"

namespace CellularNetworkDemonstration {
    class ViewWelcome:public ViewBase {
    public:
        ViewWelcome(SDL_Renderer* renderer,int viewCode);

        ~ViewWelcome();

    private:
        // ����

        // ��Դ
        SDL_Texture *m_pWelcomeImage;

        // ��Ԫ��

        // ���ƽ���Ԫ��
        virtual void doRender();

        virtual void doUpdate();
    };


}