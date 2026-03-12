#include <gtest/gtest.h>
#include <chrono>
#include <thread>
#include "Engine/Engine.h"
#include "Particle/Particle.h"
#include "Math/Vector.h"

namespace solo {
namespace engine {
namespace test {

class EngineLoopTest : public ::testing::Test {
protected:
    Engine mEngine;
};

TEST_F(EngineLoopTest, StartAndStop) {
    EXPECT_FALSE(mEngine.IsRunning());
    mEngine.Start(100.0); // 100 Hz
    EXPECT_TRUE(mEngine.IsRunning());
    mEngine.Stop();
    EXPECT_FALSE(mEngine.IsRunning());
}

TEST_F(EngineLoopTest, SimulationUpdatesParticles) {
    physics::Particle particle;
    particle.SetPosition(math::WorldCoordinates(0.0f, 0.0f, 0.0f));
    particle.SetVelocity(math::Vector(10.0f, 0.0f, 0.0f)); // 10 units/s
    
    mEngine.AddParticle(particle);
    
    // Start at 100Hz
    mEngine.Start(100.0);
    
    // Wait for approx 0.1 seconds (should be ~10 ticks)
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    
    mEngine.Stop();
    
    auto& particles = mEngine.GetParticles();
    ASSERT_EQ(particles.size(), 1);
    
    // Position should have changed from (0,0,0)
    // At 10 units/s for ~0.1s, it should be around 1.0 unit in X
    EXPECT_GT(particles[0].GetPosition().GetX(), 0.1f);
}

} // namespace test
} // namespace engine
} // namespace solo
