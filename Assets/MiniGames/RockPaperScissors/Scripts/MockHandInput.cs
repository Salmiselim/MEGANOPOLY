using UnityEngine;

namespace RockPaperScissors
{
    // Simple mock script to simulate hand gestures in editor
    public class MockHandInput : MonoBehaviour
    {
        public HandShapeDetector detector;
        
        [Header("Editor Controls")]
        public bool simulateLeftHand = true;
        public HandShapeDetector.HandShape mockShape = HandShapeDetector.HandShape.None;

        void Update()
        {
            // In a real scenario, we might override the detector's values
            // But since the detector reads directly from XR Subsystem, 
            // we can't easily injection mock data without refactoring.
            // For now, this is just a placeholder to remind us we can add keyboard overrides if needed.
        }
    }
}
