using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Camera : MonoBehaviour
{
    // Start is called before the first frame update
    public float moveSpeed = 0.5f;
    void Start()
    {
        transform.position = new Vector3(5.5f, 8.5f, -12f);
        transform.rotation = Quaternion.Euler(30f, -25f, 0f);
    }

    // Update is called once per frame
    void Update()
    {
        float verticalInput = Input.GetAxis("Vertical");
        Vector3 newPosition = transform.position + transform.forward * verticalInput * moveSpeed * Time.deltaTime;
        transform.position = newPosition;
    }
}
