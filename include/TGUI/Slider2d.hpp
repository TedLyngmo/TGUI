/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// TGUI - Texus's Graphical User Interface
// Copyright (C) 2012 Bruno Van de Velde (vdv_b@tgui.eu)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef TGUI_SLIDER2D_HPP
#define TGUI_SLIDER2D_HPP

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace tgui
{
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    class Slider2d : public ClickableObject
    {
      public:

        typedef SharedObjectPtr<Slider2d> Ptr;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Default constructor
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Slider2d();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Copy constructor
        ///
        /// \param copy  Instance to copy
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Slider2d(const Slider2d& copy);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Destructor
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual ~Slider2d();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Overload of assignment operator
        ///
        /// \param right  Instance to assign
        ///
        /// \return Reference to itself
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Slider2d& operator= (const Slider2d& right);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Makes a copy of the object by calling the copy constructor.
        // This function calls new and if you use this function then you are responsible for calling delete.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual Slider2d* clone();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Loads the object.
        ///
        /// \param configFileFilename  Filename of the config file.
        ///
        /// The config file must contain a Slider2d section with the needed information.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        bool load(const std::string& configFileFilename);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns the filename of the config file that was used to load the object.
        ///
        /// \return Filename of loaded config file.
        ///         Empty string when no config file was loaded yet.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        const std::string& getLoadedConfigFile();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Changes the size of the slider.
        ///
        /// \param width   The new width of the slider
        /// \param height  The new height of the slider
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setSize(float width, float height);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Sets a minimum value.
        ///
        /// \param minimum  The new minimum value
        ///
        /// When the value is too small then it will be changed to this minimum.
        /// The default minimum value is (-1, -1).
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setMinimum(const Vector2f& minimum);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Sets a maximum value.
        ///
        /// \param maximum  The new maximum value
        ///
        /// When the value is too big then it will be changed to this maximum.
        /// The default maximum value is (1, 1).
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setMaximum(const Vector2f& maximum);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Changes the current value.
        ///
        /// \param value  The new value
        ///
        /// The value can't be smaller than the minimum or bigger than the maximum.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setValue(const Vector2f& value);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns the minimum value.
        ///
        /// \return The current minimum value
        ///
        /// The default minimum value (-1, -1).
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Vector2f getMinimum() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns the maximum value.
        ///
        /// \return The current maximum value
        ///
        /// The default maximum value (1, 1).
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Vector2f getMaximum() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns the current value.
        ///
        /// \return The current value
        ///
        /// The default value is (0, 0).
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Vector2f getValue() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Change whether the thumb size changes when you change the size of the slider.
        ///
        /// \param fixedSize  If true then the size of the thumb doesn't change when calling setSize
        ///
        /// When \a fixedSize is set to false then the thumb will change size together with the slider.
        /// So if the slider is two times bigger than the loaded image, the thumb will also be two times bigger as its image.
        /// When \a fixedSize is set to true then the size of the thumb will always stay the same as the loaded image.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void setFixedThumbSize(bool fixedSize);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Returns whether the thumb size changes when you change the size of the slider.
        ///
        /// \return whether the thumb size changes when you change the size of the slider
        ///
        /// \see setFixedThumbSize
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        bool getFixedThumbSize() const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Decide whether or not the thumb will jump back to the center when the mouse is released.
        ///
        /// \param autoCenterThumb  Place the thumb in the center on mouse release?
        ///
        /// This behavior is disabled by default.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void enableThumbCenter(bool autoCenterThumb);


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /// \brief Places the thumb back in the center.
        ///
        /// When enableThumbCenter(true) was called then this will happen automatically when the mouse is released.
        ///
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        void centerThumb();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Used to communicate with EventManager.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void leftMousePressed(float x, float y);
        virtual void leftMouseReleased(float x, float y);
        virtual void mouseMoved(float x, float y);
        virtual void objectFocused();
        virtual void mouseNoLongerDown();


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      protected:

        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Draws the object on the render target.
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      public:

        enum Slider2dCallbacks
        {
            ValueChanged = ClickableObjectCallbacksCount * 1,
            ThumbReturnToCenter = ClickableObjectCallbacksCount * 2,
            AllSlider2dCallbacks = ClickableObjectCallbacksCount * 4 - 1,
            Slider2dCallbacksCount = ClickableObjectCallbacksCount * 4
        };


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      protected:

        std::string m_LoadedConfigFile;

        Vector2f m_Minimum;
        Vector2f m_Maximum;
        Vector2f m_Value;

        bool m_ReturnThumbToCenter;
        bool m_FixedThumbSize;

        Texture m_TextureThumbNormal;
        Texture m_TextureThumbHover;
        Texture m_TextureTrackNormal;
        Texture m_TextureTrackHover;

        bool m_SeparateHoverImage;
    };

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // TGUI_SLIDER2D_HPP
