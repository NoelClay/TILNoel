using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BulletSpawner : MonoBehaviour
{
    public GameObject bulletPrefab; //생성할 원본 프리팹
    public float spawnRateMin = 0.5f; //최소 생성 주기
    public float spawnRateMax = 3f; //최대 생성 주기

    Transform target; //향할 대상
    float spawnRate; //생성 주기
    float timeAfterSpawn; //최근 생성 시점에서 흐른 시간

    void Start()
    {
        timeAfterSpawn = 0f;    //처음 생성시간 초기화
        spawnRate = Random.Range(spawnRateMin, spawnRateMax); //스폰 주기 랜덤값으로 초기화
        target = FindObjectOfType<PlayerController>().transform; //플레이어 컨트롤러의 위치로
    }

    // Update is called once per frame
    void Update()
    {
        timeAfterSpawn += Time.deltaTime;
        if(timeAfterSpawn >= spawnRate)
        {
            timeAfterSpawn = 0f;
            GameObject bullet = 
                Instantiate(bulletPrefab, transform.position, transform.rotation);
            bullet.transform.LookAt(target);
            spawnRate = Random.Range(spawnRateMin, spawnRateMax);
        }
    }
}
