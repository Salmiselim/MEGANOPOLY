using UnityEngine;

/// <summary>
/// Makes this GameObject always rotate to face the main camera.
/// Attach to any World Space Canvas that should billboard toward the player.
/// </summary>
public class FaceCamera : MonoBehaviour
{
    private void Update()
    {
        if (Camera.main == null) return;
        transform.LookAt(Camera.main.transform);
        transform.Rotate(0f, 180f, 0f); // flip so the front faces the camera
    }
}
