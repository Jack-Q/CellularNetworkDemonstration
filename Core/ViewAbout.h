#pragma once
#include "ViewBase.h"

namespace CellularNetworkDemonstration {
    class ViewAbout :public ViewBase {
    public:
        ViewAbout(SDL_Renderer* renderer, int viewCode);

        ~ViewAbout();

    private:
        // ����

        // ��Դ
        SDL_Texture *m_pAboutImage;

        // ��Ԫ��

        // ���ƽ���Ԫ��
        virtual void doRender();

        virtual void doUpdate();
    };


}