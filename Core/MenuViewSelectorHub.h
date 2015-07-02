#pragma once
#include "Include.h"
#include "UIBase.h"
#include "MenuViewSelector.h"

namespace CellularNetworkDemonstration {
    class MenuViewSelectorHub : public UIBase {

    public:
        MenuViewSelectorHub(SDL_Renderer *renderer)
            :UIBase(renderer, 400, 30) {
            //��ʼ����Ԫ��
            m_pViewSelectors[0] = new MenuViewSelector(m_pRenderer, "��ӭ");
            m_pViewSelectorRects[0] = new SDL_Rect{ 15, 0, 70, 30 };

            m_pViewSelectors[1] = new MenuViewSelector(m_pRenderer, "����");
            m_pViewSelectorRects[1] = new SDL_Rect{ 115, 0, 70, 30 };

            m_pViewSelectors[2] = new MenuViewSelector(m_pRenderer, "��ʾ");
            m_pViewSelectorRects[2] = new SDL_Rect{ 215, 0, 70, 30 };

            m_pViewSelectors[3] = new MenuViewSelector(m_pRenderer, "����");
            m_pViewSelectorRects[3] = new SDL_Rect{ 315, 0, 70, 30 };


            // ��������
            m_iViewIndex = 0;
        }
        ~MenuViewSelectorHub() {
            // ������Ԫ�غ���Դ
            for (int i = 0; i < 4; i++) {
                DELETE_IF_EXIST(m_pViewSelectors[i]);
                DELETE_IF_EXIST(m_pViewSelectorRects[i]);
            }

        }
        inline void setViewIndex(int index) {
            //TODO: Do page changing.
            m_iViewIndex = index;
        }

        inline int getViewIndex() const {
            return m_iViewIndex;
        }
    private:
        // ����
        int m_iViewIndex;

        // ��Ԫ��
        MenuViewSelector *m_pViewSelectors[4];
        SDL_Rect *m_pViewSelectorRects[4];

        // ���ƽ���Ԫ��
        virtual void doRender() {
            SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 0);
            SDL_RenderClear(m_pRenderer);
            for (int i = 0; i < 4; i++) {

                SDL_Texture *texture = m_pViewSelectors[i]->render();
                SDL_RenderCopy(m_pRenderer, texture, m_pViewSelectors[i]->Rect(), m_pViewSelectorRects[i]);
            }
        }

        // 
        virtual void doUpdate() {
            for (int i = 0; i < 4; i++) {
                if (SDL_PointInRect(m_sMousePosition, *m_pViewSelectorRects[i])) {
                    m_pViewSelectors[i]->update(SDL_RelationPoint(&m_sMousePosition, m_pViewSelectorRects[i]));
                } else {
                    m_pViewSelectors[i]->update(SDL_Point{ -1, -1 });
                }
            }
        }
    };
}