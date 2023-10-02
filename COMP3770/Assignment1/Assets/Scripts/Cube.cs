using System.Collections;
using System.Collections.Generic;
using Unity.VisualScripting;
using UnityEngine;

public class Cube : MonoBehaviour
{
    // Start is called before the first frame update
    public int speed = 5;
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        gameObject.transform.Translate(0, speed, 0);
    }
    public void FixedUpdate()
    {
        gameObject.transform.Translate(0, speed + Time.fixedDeltaTime, 0);
    }
}
