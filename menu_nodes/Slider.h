#ifndef SLIDER_H
#define SLIDER_H

#include <gd.h>

namespace gd {

    class SliderThumb : public cocos2d::CCMenuItemImage {
        protected:
            float m_fPosition;
            bool m_bVertical;

        public:
            void setValue(float val) {
                reinterpret_cast<void(__fastcall*)(
                    SliderThumb*, float
                )>( base + 0x2e1b0 )( this, val );
            }
    };

    class SliderTouchLogic : public cocos2d::CCMenu {
        protected:
            PAD(0x4)
            float m_fLength;
            SliderThumb* m_pThumb;
            Slider* m_pSlider;
            m_bUnknown;
            PAD(0x8)
            bool m_bVertical;

        public:
            SliderThumb* getThumb() const { return m_pThumb; }
    };

    class Slider : public cocos2d::CCLayer {
        protected:
            SliderTouchLogic* m_pTouchLogic;
            cocos2d::CCSprite* m_pSliderBar;
            cocos2d::CCSprite* m_pGroove;
            float m_fUnknown;
            float m_fHeight;

        public:
            void setValue(float val) {
                this->m_pTouchLogic->getThumb()->setValue(val);
            }

            static Slider* create(
                cocos2d::CCNode* target,
                cocos2d::SEL_MenuHandler click,
                const char* grooveSpr,
                const char* thumbSpr,
                const char* thumbSprSel,
                float scale
            ) {
                return reinterpret_cast<Slider*(__fastcall*)(
                    cocos2d::CCNode*, cocos2d::SEL_MenuHandler, const char*,
                    const char*, const char*, const char*, float
                )>(
                    base + 0x2e6e0
                )(
                    target, click, nullptr, grooveSpr, thumbSpr, thumbSprSel
                );
            }

        // todo
    };

}

#endif
