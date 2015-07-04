#pragma once
#include "UIBase.h"
#include "DemoDataManager.h"
#include "DemoBaseStationListItem.h"
#include "DemoMobileClientListItem.h"

namespace CellularNetworkDemonstration {
    class DemoSidebar : public UIBase {
    public:
        DemoSidebar(SDL_Renderer *renderer)
            :UIBase(renderer, 600, 440) {
            // ���ñ�������ʾ���Ϊ195px����Ϊ������ʾ
            // �������������ذ�ť��ÿһ����Ŀ��Ϊ
            // 195px���Լ�5px�߿���ת������ʱֱ��ת��
            // �����������꼴�ɡ�
            this->m_pRect->w = 195;

            SDL_Texture* origTarget = SDL_GetRenderTarget(m_pRenderer);
            Uint8 r, g, b, a;
            SDL_GetRenderDrawColor(m_pRenderer, &r, &g, &b, &a);
            SDL_Texture *temp;

            SDL_SetRenderTarget(m_pRenderer, m_pTexture);
            SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 0);
            SDL_RenderClear(m_pRenderer);

            int w, h;
            SDL_Rect rect;
            SDL_Color color{ 80, 75, 70, 255 };
            // �������
            m_pTitleText = TTF_RenderTextTexture(renderer, "��ʾԪ��", 22, &color);
            SDL_QueryTexture(m_pTitleText, nullptr, nullptr, &w, &h);
            m_pTitleTextRect = new SDL_Rect{ 10, -5, w, h };

            // ��վ�б����
            temp = TTF_RenderTextTexture(renderer, "��վ", 18, &color);
            SDL_QueryTexture(temp, nullptr, nullptr, &w, &h);
            m_pBaseStationListTitle = SDL_CreateTexture(m_pRenderer,
                SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 190, 20);
            SDL_SetTextureBlendMode(m_pBaseStationListTitle, SDL_BLENDMODE_BLEND);
            SDL_SetRenderTarget(m_pRenderer, m_pBaseStationListTitle);
            SDL_SetRenderDrawColor(m_pRenderer, 180, 180, 180, 120);
            SDL_RenderDrawLine(renderer, 5, 6, 190, 6);
            SDL_RenderDrawLine(renderer, 5, 9, 190, 9);
            SDL_RenderDrawLine(renderer, 5, 12, 190, 12);
            rect = { 15, -4, w + 10, h };
            SDL_SetRenderDrawColor_DefalutBackground(m_pRenderer);
            SDL_RenderFillRect(m_pRenderer, &rect);
            rect = { 20, -4, w, h };
            SDL_RenderCopy(m_pRenderer, temp, nullptr, &rect);
            SDL_DestroyTexture(temp);
            m_pBaseStationListTitleRect = new SDL_Rect{ 0, 30, 190, 20 };


            // �ƶ�̨�б����           
            temp = TTF_RenderTextTexture(renderer, "�ƶ�̨", 18, &color);
            SDL_QueryTexture(temp, nullptr, nullptr, &w, &h);
            m_pMobileClientListTitle = SDL_CreateTexture(m_pRenderer,
                SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 190, 20);
            SDL_SetTextureBlendMode(m_pMobileClientListTitle, SDL_BLENDMODE_BLEND);
            SDL_SetRenderTarget(m_pRenderer, m_pMobileClientListTitle);
            SDL_SetRenderDrawColor(m_pRenderer, 180, 180, 180, 120);
            SDL_RenderDrawLine(renderer, 5, 6, 190, 6);
            SDL_RenderDrawLine(renderer, 5, 9, 190, 9);
            SDL_RenderDrawLine(renderer, 5, 12, 190, 12);
            rect = { 15, -4, w + 10, h };
            SDL_SetRenderDrawColor_DefalutBackground(m_pRenderer);
            SDL_RenderFillRect(m_pRenderer, &rect);
            rect = { 20, -4, w, h };
            SDL_RenderCopy(m_pRenderer, temp, nullptr, &rect);
            SDL_DestroyTexture(temp);
            m_pMobileClientListTitleRect = new SDL_Rect{ 0, 180, 190, 20 };

            // ��ӻ�վ�б�

            vector<MainBaseStation *>& baseStationList =
                DemoDataManager::get().getBaseStationList();
            for (unsigned int i = 0; i < baseStationList.size(); i++) {
                DemoBaseStationListItem *listItem =
                    new DemoBaseStationListItem(m_pRenderer, baseStationList[i]->getId());
                m_vpBaseStationList.push_back(listItem);

            }

            // ����ƶ�̨�б�
            vector<MainMobileClient *>& mobileClientList =
                DemoDataManager::get().getMobileClientList();
            for (unsigned int i = 0; i < mobileClientList.size(); i++) {
                DemoMoblieClientListItem *listItem =
                    new DemoMoblieClientListItem(m_pRenderer, mobileClientList[i]->getId());
                m_vpMobileClientList.push_back(listItem);

            }

            // �����ϼ�ͼ��
            m_pArrow = IMG_LoadTexture(renderer, "left-arrow.png");
            m_pArrowLv1Rect = new SDL_Rect{ 205, 0, 30, 30 };
            m_pArrowLv2Rect = new SDL_Rect{ 405, 0, 30, 30 };

            // �ָ���Ⱦ��״̬
            SDL_SetRenderTarget(m_pRenderer, origTarget);
            SDL_SetRenderDrawColor(m_pRenderer, r, g, b, a);


        }

        ~DemoSidebar() {
            // ������Ԫ�غ���Դ

            //DELETE_IF_EXIST(m_pMenuSystemMinimize)
            //    if (m_pMenuImage) {
            //        SDL_DestroyTexture(m_pMenuImage);
            //    }
            DELETE_IF_EXIST(m_pBaseStationListTitleRect)
                DELETE_IF_EXIST(m_pTitleTextRect)
                DELETE_IF_EXIST(m_pMobileClientListTitleRect)
                if (m_pTitleText) {
                    SDL_DestroyTexture(m_pTitleText);
                }
            if (m_pBaseStationListTitle) {
                SDL_DestroyTexture(m_pBaseStationListTitle);
            }
            if (m_pMobileClientListTitle) {
                SDL_DestroyTexture(m_pMobileClientListTitle);
            }
        }

        void deepLevel() {
            setLevel(m_iCurrentLevel + 1);
        }
        void upLevel() {
            setLevel(m_iCurrentLevel - 1);
        }

        void setLevel(int level) {
            if (level < 0) {
                level = 0;
            }
            if (level > 2) {
                level = 2;
            }
            if (level == m_iCurrentLevel) {
                return;
            }
            m_iPreviousLevel = m_iCurrentLevel;
            m_iCurrentLevel = level;
            m_bSwitching = true;
        }

        virtual bool handleEvents(SDL_Event &event) {
            if (event.user.code & SDL_DEMO_SIDEBAR) {
                switch (event.user.code) {
                    case SDL_DEMO_SIDEBAR_BASE_STATION:
                    {
                        int baseStation = *(int *) (event.user.data1);
                    }
                    setLevel(1);
                    return true;
                    case SDL_DEMO_SIDEBAR_MOBILE_CLIENT:
                    {
                        int baseStation = *(int *) (event.user.data1);
                    }
                    setLevel(1);
                    return true;
                    case SDL_DEMO_SIDEBAR_CHIPSET:
                    {
                        int baseStation = *(int *) (event.user.data1);
                    }
                    setLevel(2);
                    return true;
                }
            }
            return false;
        }

    private:
        // ����
        bool m_bSwitching = false;
        int m_iSelectedTypeLv1 = 0; // 0 - ��վ�� 1 - �ƶ�̨
        int m_iSelectedTypeLv2 = 1;
        int m_iCurrentLevel = 0;
        int m_iPreviousLevel = 0;


        // ��Դ
        SDL_Texture *m_pTitleText;
        SDL_Rect *m_pTitleTextRect;
        SDL_Texture *m_pBaseStationListTitle;
        SDL_Rect *m_pBaseStationListTitleRect;
        SDL_Texture *m_pMobileClientListTitle;
        SDL_Rect *m_pMobileClientListTitleRect;
        SDL_Texture *m_pArrow;
        SDL_Rect *m_pArrowLv1Rect;
        SDL_Rect *m_pArrowLv2Rect;

        vector<DemoBaseStationListItem *> m_vpBaseStationList;
        vector<DemoMoblieClientListItem *> m_vpMobileClientList;

        // ��Ԫ��
        //MenuSystemClose *m_pMenuSystemClose;
        //SDL_Rect *m_pMenuSystemCloseRect;


        // ���ƽ���Ԫ��
        virtual void doRender() {
            SDL_SetRenderDrawColor_DefalutBackground(m_pRenderer);
            SDL_RenderClear(m_pRenderer);
            renderLevel(m_iCurrentLevel);
            if (m_bSwitching) {
                renderLevel(m_iPreviousLevel);
            }
            m_pRect->x = getAnimationValue();
        }
        void renderLevel(int l) {
            switch (l) {
                case 0:
                    // ������ҳ��
                    SDL_Texture *texture;
                    SDL_Rect rect;
                    SDL_RenderCopy(m_pRenderer, m_pTitleText, nullptr, m_pTitleTextRect);
                    SDL_RenderCopy(m_pRenderer, m_pBaseStationListTitle, nullptr, m_pBaseStationListTitleRect);
                    SDL_RenderCopy(m_pRenderer, m_pMobileClientListTitle, nullptr, m_pMobileClientListTitleRect);

                    // ���ƻ�վ�б���
                    rect.x = 5;
                    rect.w = 185;
                    rect.h = 20;
                    for (unsigned int i = 0; i < m_vpBaseStationList.size(); i++) {
                        rect.y = 50 + i * 21;
                        texture = m_vpBaseStationList[i]->render();
                        SDL_RenderCopy(m_pRenderer, texture, m_vpBaseStationList[i]->Rect(), &rect);
                    }


                    // �����ƶ�̨�б���
                    rect.x = 5;
                    rect.w = 185;
                    rect.h = 20;
                    for (unsigned int i = 0; i < m_vpMobileClientList.size(); i++) {
                        rect.y = 200 + i * 21;
                        texture = m_vpMobileClientList[i]->render();
                        SDL_RenderCopy(m_pRenderer, texture, m_vpMobileClientList[i]->Rect(), &rect);
                    }
                    break;
                case 1:
                    // ����һ���˵�
                    // ���Ʒ����ϼ�ͼ��
                    SDL_RenderCopy(m_pRenderer, m_pArrow, nullptr, m_pArrowLv1Rect);
                    
                    break;
                case 2:
                    // ���ƶ����˵�
                    // ���Ʒ����ϼ�ͼ��
                    SDL_RenderCopy(m_pRenderer, m_pArrow, nullptr, m_pArrowLv2Rect);

                    break;
            }

        }

        int getAnimationValue() {

            const static int DURATION = 500 / 100;
            static int percent = 0;
            static int lastTick = 0;
            static int currentTick;
            currentTick = SDL_GetTicks();
            int animatiionValue = 200 * m_iCurrentLevel;
            int delta;
            switch (m_iCurrentLevel) {
                case 0:
                    if (percent != 0) {
                        delta = (currentTick - lastTick) / DURATION;
                        percent -= delta;
                        if (percent <= 0) {
                            percent = 0;
                            m_bSwitching = false;
                        }
                        // ������������Ϊ����
                        animatiionValue = SDL_static_cast(int, 200 * easeInOut(percent / 100.0));
                    }
                    break;
                case 1:
                    if (percent != 100) {
                        if (percent < 100) {
                            delta = (currentTick - lastTick) / DURATION;
                            percent += delta;
                            if (percent >= 100) {
                                percent = 100;
                                m_bSwitching = false;
                            }
                            // ������������Ϊ����
                            animatiionValue = SDL_static_cast(int, 200 * easeInOut(percent / 100.0));
                        }
                        else {
                            delta = (currentTick - lastTick) / DURATION;
                            percent -= delta;
                            if (percent <= 100) {
                                percent = 100;
                                m_bSwitching = false;
                            }
                            // ������������Ϊ����
                            animatiionValue = SDL_static_cast(int, 200 * easeInOut((percent - 100) / 100.0));
                        }

                    }
                    break;
                case 2:
                    if (percent != 200) {
                        delta = (currentTick - lastTick) / DURATION;
                        percent += delta;
                        if (percent >= 200) {
                            percent = 200;
                            m_bSwitching = false;
                        }
                        // ������������Ϊ����
                        animatiionValue = SDL_static_cast(int, 200 * easeInOut((percent - 100) / 100.0));

                    }
                    break;
            }
            lastTick = currentTick;
            return animatiionValue;
        }

        inline double easeInOut(double val) {
            return (-0.5 * (SDL_cos(3.14159 * val) - 1));
        }

        virtual void doUpdate() {
            if (m_bSwitching) {
                return;
            }
            SDL_log(m_sMousePosition.x);
            SDL_log(m_sMousePosition.y);
            switch (m_iCurrentLevel) {

                case 0:
                {


                    SDL_Rect rect;
                    rect.x = 5;
                    rect.w = 185;
                    rect.h = 20;
                    for (unsigned int i = 0; i < m_vpBaseStationList.size(); i++) {
                        rect.y = 50 + i * 21;
                        if (SDL_PointInRect(m_sMousePosition, rect)) {
                            m_vpBaseStationList[i]->update(SDL_RelationPoint(&m_sMousePosition, &rect));
                        }
                        else {
                            m_vpBaseStationList[i]->update();
                        }
                    }

                    rect.x = 5;
                    rect.w = 185;
                    rect.h = 20;
                    for (unsigned int i = 0; i < m_vpMobileClientList.size(); i++) {
                        rect.y = 200 + i * 21;
                        if (SDL_PointInRect(m_sMousePosition, rect)) {

                            m_vpMobileClientList[i]->update(SDL_RelationPoint(&m_sMousePosition, &rect));
                        }
                        else {
                            m_vpMobileClientList[i]->update();
                        }
                    }
                    break;
                case 1:
                    if (SDL_PointInRect(m_sMousePosition, *m_pArrowLv1Rect) && MouseManager::get().isLeftButtonDown()) {
                        upLevel();
                    }
                    break;
                case 2:
                    if (SDL_PointInRect(m_sMousePosition, *m_pArrowLv2Rect) && MouseManager::get().isLeftButtonDown()) {
                        upLevel();
                    }
                    break;
                }
            }
        }
    };
}