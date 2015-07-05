#pragma once
#include "UIBase.h"
#include "ViewBase.h"

#include "ViewWelcome.h"
#include "ViewIntroduce.h"
#include "ViewDemonstration.h"
#include "ViewAbout.h"

namespace CellularNetworkDemonstration {
    class ViewPanel 
        :public UIBase {
    public:
        ViewPanel(SDL_Renderer *renderer);
        ~ViewPanel();
        void setViewCode(int indexCode);

        virtual bool handleEvents(SDL_Event &event);

        bool isSwitching() const;
    private:
        // ����
        int m_iViewIndex;
        int m_iViewPreviousIndex;
        bool m_bSwitching;
        // ��Ԫ��
        ViewBase *m_pViews[4];

        // ���ƽ���Ԫ��
        virtual void doRender();

        int getContiniousValue(int interval);

        virtual void doUpdate();

    };
}


