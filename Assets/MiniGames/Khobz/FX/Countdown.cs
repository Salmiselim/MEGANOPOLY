using UnityEngine;
public class PulseText : MonoBehaviour
{
    void Update()
    {
        float scale = 1f + Mathf.Sin(Time.time * 4f) * 0.1f;
        transform.localScale = new Vector3(scale, scale, scale);
    }
}