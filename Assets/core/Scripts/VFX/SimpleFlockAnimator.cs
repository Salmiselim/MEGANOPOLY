using UnityEngine;

namespace Meganopoly.VFX
{
    public class SimpleFlockAnimator : MonoBehaviour
    {
        [Header("Movement Settings")]
        public float speed = 5f;
        public float rotationSpeed = 2f;
        [Tooltip("The horizontal/X radius of the flight path. Make this larger for more horizontal travel.")]
        public float radiusX = 40f;
        [Tooltip("The depth/Z radius of the flight path.")]
        public float radiusZ = 20f;
        
        [Header("Height Variation")]
        [Tooltip("How much the bird/drone moves up and down.")]
        public float heightVariation = 2f;
        [Tooltip("How fast the bird/drone moves up and down.")]
        public float heightSpeed = 1f;
        
        private Vector3 centerPoint;
        private float currentAngle;

        private void Start()
        {
            centerPoint = transform.position;
            // Randomize start angle so they don't all clump together if you have multiple
            currentAngle = Random.Range(0f, 360f);
        }

        private void Update()
        {
            currentAngle += speed * Time.deltaTime;
            
            float rad = currentAngle * Mathf.Deg2Rad;
            float x = Mathf.Cos(rad) * radiusX;
            float z = Mathf.Sin(rad) * radiusZ;
            float y = Mathf.Sin(Time.time * heightSpeed + currentAngle) * heightVariation;

            Vector3 targetPosition = centerPoint + new Vector3(x, y, z);
            Vector3 direction = (targetPosition - transform.position).normalized;

            if (direction != Vector3.zero)
            {
                Quaternion targetRotation = Quaternion.LookRotation(direction);
                transform.rotation = Quaternion.Slerp(transform.rotation, targetRotation, rotationSpeed * Time.deltaTime);
            }

            transform.position = Vector3.Lerp(transform.position, targetPosition, Time.deltaTime * speed);
        }
    }
}
