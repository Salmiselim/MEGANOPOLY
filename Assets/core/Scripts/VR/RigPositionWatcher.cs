using UnityEngine;

/// <summary>
/// Drop this on the XR Origin to log who/what moves the rig at runtime.
/// Logs every frame the position changes from the previous frame, with a stack hint.
/// Remove once you've found the offending mover.
/// </summary>
[DefaultExecutionOrder(10000)]
public class RigPositionWatcher : MonoBehaviour
{
    [Tooltip("Minimum movement (meters) before a log fires. Avoids spam from float drift.")]
    public float minDelta = 0.05f;

    private Vector3 _last;
    private int _frameCount;

    private void Awake()
    {
        _last = transform.position;
        Debug.Log($"[RigWatcher] AWAKE pos={_last} on '{gameObject.name}' (frame {Time.frameCount})", this);
    }

    private void Start()
    {
        Debug.Log($"[RigWatcher] START pos={transform.position} (frame {Time.frameCount})", this);
        _last = transform.position;
    }

    private void LateUpdate()
    {
        var p = transform.position;
        if (Vector3.Distance(p, _last) >= minDelta)
        {
            _frameCount++;
            Debug.LogWarning($"[RigWatcher] MOVED frame {Time.frameCount} (#{_frameCount}): {_last:F2} → {p:F2}  delta={Vector3.Distance(p, _last):F2}m  parent={transform.parent?.name ?? "(none)"}", this);
            _last = p;
        }
    }
}
