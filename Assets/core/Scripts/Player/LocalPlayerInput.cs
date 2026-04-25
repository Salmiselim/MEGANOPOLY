using UnityEngine;
using Unity.Netcode;

public class LocalPlayerInput : NetworkBehaviour
{
    [SerializeField] private KeyCode rollKey = KeyCode.Space;

    private void Update()
    {
        if (!IsOwner) return;

        if (Input.GetKeyDown(rollKey))
        {
            Debug.Log($"[Input] Space pressed! IsOwner={IsOwner} GM={CompleteGameManager.Instance != null}");
            CompleteGameManager.Instance?.RequestRoll();
        }
    }
}