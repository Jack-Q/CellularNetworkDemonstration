#pragma once
#include "StdInclude.h"

#define DELETE_IF_EXIST(POINTER) if(POINTER){delete (POINTER);}
#define DELETE_IF_EXIST_TEXTURE(TEXTURE) if(TEXTURE){SDL_DestroyTexture(TEXTURE);}

namespace CellularNetworkDemonstration {



    SDL_FORCE_INLINE void SDL_log(long double num) {
#ifdef DEBUG
        std::cout << num << std::endl;
#endif // DEBUG
    }

    SDL_FORCE_INLINE void SDL_log(const char *str) {
#ifdef DEBUG
        std::cout << str << std::endl;
#endif // DEBUG
    }

    // �ж������Ƿ������ھ�����
    SDL_FORCE_INLINE SDL_bool SDL_PointInRect(const SDL_Point *p, const SDL_Rect *r) {
        return ( ( p->x >= r->x ) && ( p->x < ( r->x + r->w ) ) &&
            ( p->y >= r->y ) && ( p->y < ( r->y + r->h ) ) ) ? SDL_TRUE : SDL_FALSE;
    }

    // �ж������Ƿ������ھ�����
    SDL_FORCE_INLINE SDL_bool SDL_PointInRect(const SDL_Point &p, const SDL_Rect &r) {
        return ( ( p.x >= r.x ) && ( p.x < ( r.x + r.w ) ) &&
            ( p.y >= r.y ) && ( p.y < ( r.y + r.h ) ) ) ? SDL_TRUE : SDL_FALSE;
    }

    // �ж������Ƿ������ھ�����
    SDL_FORCE_INLINE SDL_bool SDL_PointInRect(const int &x, const int &y, const SDL_Rect &r) {
        return ( ( x >= r.x ) && ( x < ( r.x + r.w ) ) &&
            ( y >= r.y ) && ( y < ( r.y + r.h ) ) ) ? SDL_TRUE : SDL_FALSE;
    }

    // ��ȡ������ھ��������λ��
    SDL_FORCE_INLINE SDL_Point SDL_RelationPoint(const SDL_Point *p, const SDL_Rect *r) {
        return SDL_Point{ p->x - r->x, p->y - r->y };
    }

    // ��ȡ������ھ��������λ��
    SDL_FORCE_INLINE SDL_Point SDL_DeRelationPoint(const SDL_Point *p, const SDL_Rect *r) {
        return SDL_Point{ r->x + p->x , r->y + p->y };
    }

    // ��׼����ϵ��
    enum TTF_FontFamilySeries {
        // �޳�������
        TTF_FONT_SANS_SERIF,
        // ��������
        TTF_FONT_SERIF,
        // �ȿ�����
        TTF_FONT_MONOSPACE,

        // Ĭ����������Ϊ�޳�������
        TTF_FONT_DEFAULT = TTF_FONT_SANS_SERIF
    };

    // ��Ⱦ����
    SDL_Texture *TTF_RenderTextTexture(SDL_Renderer *renderer,
        const std::string &message,
        int fontSize,
        SDL_Color *color = nullptr,
        TTF_FontFamilySeries fontFamily = TTF_FONT_DEFAULT);

   


    SDL_FORCE_INLINE void SDL_SetRenderDrawColor_DefalutBackground(SDL_Renderer *renderer) {
        SDL_SetRenderDrawColor(renderer, 235, 235, 235, 255);
    }

    // ��С���¼�
    static const int SDL_MINIMIZE = 0x00000001;

    // ҳ���л��¼�
    static const int SDL_CHANGEVIEW = 0x00000100;
    static const int SDL_CHANGEVIEW_01 = 0x00000101;
    static const int SDL_CHANGEVIEW_02 = 0x00000102;
    static const int SDL_CHANGEVIEW_03 = 0x00000103;
    static const int SDL_CHANGEVIEW_04 = 0x00000104;

    // ��ʾ�˵��л��¼�

    static const int SDL_DEMO_SIDEBAR = 0x00000200;
    // ��վ��ϸ��Ϣ��ʾ��data1Ϊint���ݣ���վid
    static const int SDL_DEMO_SIDEBAR_BASE_STATION = 0x00000201;
    // �ƶ�̨��ϸ��Ϣ��ʾ��data1Ϊint���ݣ��ƶ�̨id
    static const int SDL_DEMO_SIDEBAR_MOBILE_CLIENT = 0x00000202;
    static const int SDL_DEMO_SIDEBAR_KEYBOARD = 0x00000203;
    static const int SDL_DEMO_SIDEBAR_SCREEN = 0x00000204;
    static const int SDL_DEMO_SIDEBAR_CHIPSET = 0x00000205;
}