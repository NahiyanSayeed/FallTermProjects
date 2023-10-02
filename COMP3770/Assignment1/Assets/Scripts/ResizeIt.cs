using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ResizeIt : MonoBehaviour
{
    // Start is called before the first frame update
    [SerializeField] float sizeToCover;
    [SerializeField] float speed;
    private Vector3 temp;
    void Start()
    {
        temp = transform.localScale;
    }

    // Update is called once per frame
    void Update()
    {
        Vector3 v = temp;
        v.x += sizeToCover * Mathf.Abs(Mathf.Sin(Time.time * speed));
        v.y += sizeToCover * Mathf.Abs(Mathf.Sin(Time.time * speed));
        v.z += sizeToCover * Mathf.Abs(Mathf.Sin(Time.time * speed));

        transform.localScale = v;

    }
}
