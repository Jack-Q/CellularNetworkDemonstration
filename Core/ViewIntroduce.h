#pragma once
#include "ViewBase.h"

namespace CellularNetworkDemonstration {
    class ViewIntroduce :public ViewBase {
    public:
        ViewIntroduce(SDL_Renderer* renderer, int viewCode);

        ~ViewIntroduce();

    private:
        // ����

        // ��Դ
        SDL_Texture *m_pIntroduceImage;

        // ��Ԫ��

        // ���ƽ���Ԫ��
        virtual void doRender();

        virtual void doUpdate();
    };


}