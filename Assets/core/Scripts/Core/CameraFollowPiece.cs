using UnityEngine;
using Unity.Netcode;

public class CameraFollowPiece : MonoBehaviour
{
    [Header("Follow Settings")]
    public Transform target;
    public Vector3 offset = new Vector3(0f, 2f, -3f); // Adjust this to sit behind/above the piece
    public float followSpeed = 5f;

    [Header("Rotation Settings")]
    public bool matchTargetRotation = false;

    private void LateUpdate()
    {
        if (target == null)
            return;

        // Smoothly follow the piece
        Vector3 desiredPosition = target.position + offset;
        transform.position = Vector3.Lerp(transform.position, desiredPosition, Time.deltaTime * followSpeed);

        if (matchTargetRotation)
        {
            transform.rotation = Quaternion.Slerp(transform.rotation, target.rotation, Time.deltaTime * rotationSpeed());
        }
        else
        {
            // Always look directly at the piece (or center of board)
            transform.LookAt(target.position + Vector3.up);
        }
    }

    private float rotationSpeed() => 5f;

    /// <summary>
    /// Call this from GameManager to set the camera's target
    /// </summary>
    public void SetTarget(Transform newTarget)
    {
        target = newTarget;
        
        // Snap immediately so there is no awkward sliding at the start
        if (target != null)
        {
            transform.position = target.position + offset;
            transform.LookAt(target.position + Vector3.up);
        }
    }
}
