
#include "Animation.hpp"

namespace sfu
{
    
    ////////////////////////////////////////////////////////////
    Animation::Animation()
    {}

    ////////////////////////////////////////////////////////////
    Animation::Animation(sf::Vector2i AnimationStart, sf::Vector2i FrameSize,
                         unsigned int FramesNum, float Speed)
    {
        m_startpos = AnimationStart;
        m_frame_size = FrameSize;
        m_frames_num = FramesNum;
        m_speed = Speed;
        m_time = 0;
        m_frame_current = 0;
    }
    
    ////////////////////////////////////////////////////////////
    void Animation::SetStartPosition(const sf::Vector2i StartPosition)
    {
        m_startpos = StartPosition;
    }
    
    ////////////////////////////////////////////////////////////
    void Animation::SetFrameSize(const sf::Vector2i FrameSize)
    {
        m_frame_size = FrameSize;
    }
    
    ////////////////////////////////////////////////////////////
    void Animation::SetNumFrames(const unsigned int FrameCount)
    {
        m_frames_num = FrameCount;
    }
    
    ////////////////////////////////////////////////////////////
    void Animation::SetSpeed(const float speed)
    {
        m_speed = speed;
    }
    
    ////////////////////////////////////////////////////////////
    const sf::Vector2i Animation::GetStartPosition() const
    {
        return m_startpos;
    }
    
    ////////////////////////////////////////////////////////////
    const sf::Vector2i Animation::GetFrameSize() const
    {
        return m_frame_size;
    }
    
    ////////////////////////////////////////////////////////////
    const unsigned int Animation::GetNumFrames() const
    {
        return m_frames_num;
    }
    
    ////////////////////////////////////////////////////////////
    const float Animation::GetSpeed() const
    {
        return m_speed;
    }

    ////////////////////////////////////////////////////////////
    void Animation::Update(const float etime)
    {
        m_time += etime;
        if (m_time >= m_speed) {
            
            m_frame_current++;

            if (m_frame_current >= m_frames_num)
                m_frame_current = 0;

            m_time = 0;
        }
    }

    ////////////////////////////////////////////////////////////
    sf::IntRect Animation::GetFrame() const
    {
        return sf::IntRect(m_startpos.x + m_frame_current * m_frame_size.x,
                       m_startpos.y, m_frame_size.x, m_frame_size.y);
    }

}