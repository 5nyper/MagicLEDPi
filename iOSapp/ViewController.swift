//
//  ViewController.swift
//  MagicLEDPi
//
//  Created by Vikaton on 12/10/15.
//  Copyright © 2015 Vikaton. All rights reserved.
//

import UIKit
import Alamofire

enum Color: Int {
    case Red =    0
    case Green =  1
    case Blue =   2
    case Purple = 3
    case Pink =   4
    case Orange = 5
    case White =  6
}

class ViewController: UIViewController {
    @IBOutlet weak var red: UIButton!
    @IBOutlet weak var green: UIButton!
    @IBOutlet weak var blue: UIButton!
    @IBOutlet weak var purple: UIButton!
    @IBOutlet weak var pink: UIButton!
    @IBOutlet weak var yellow: UIButton!
    @IBOutlet weak var white: UIButton!
    @IBOutlet weak var patt: UISegmentedControl!
    override func viewDidLoad() {
        super.viewDidLoad()
        red.backgroundColor = UIColor.redColor()
        green.backgroundColor = UIColor.greenColor()
        blue.backgroundColor = UIColor.blueColor()
        purple.backgroundColor = UIColor.purpleColor()
        pink.backgroundColor = UIColor.magentaColor()
        yellow.backgroundColor = UIColor.orangeColor()
        white.backgroundColor = UIColor.whiteColor()
        let buttons: [UIButton] = [red,green,blue,purple,pink,yellow,white]
        for x in buttons {
            x.layer.cornerRadius = 50;
        }
        Alamofire.request(.GET, "https://0.0.0.0/")
            .responseString { response in
                if response.result.value == nil {
                    let alert = UIAlertView()
                    alert.title = "No Internet Connection"
                    alert.message = "Please connect to the Internet to control the LEDs"
                    alert.addButtonWithTitle("Ok")
                    alert.show()
                }
        }
        
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    @IBAction func onTouch(sender: UIButton!) {
        if sender.backgroundColor!.isEqual(UIColor.redColor()) {
            print("https://0.0.0.0/app?func=\(patt.selectedSegmentIndex)&color=\(Color.Red.rawValue)")
            Alamofire.request(.GET, "https://0.0.0.0/app?func=\(patt.selectedSegmentIndex)&color=\(Color.Red.rawValue)")
                .responseString { response in
                print(response.result)
            }
        }
        else if sender.backgroundColor!.isEqual(UIColor.magentaColor()) {
            Alamofire.request(.GET, "https://0.0.0.0/app?func=\(patt.selectedSegmentIndex)&color=\(Color.Pink.rawValue)")
                .responseString { response in
                    print(response.result)
            }
        }

        else if sender.backgroundColor!.isEqual(UIColor.greenColor()) {
            Alamofire.request(.GET, "https://0.0.0.0/app?func=\(patt.selectedSegmentIndex)&color=\(Color.Green.rawValue)")
                .responseString { response in
                    print(response.result)
            }
        }
        else if sender.backgroundColor!.isEqual(UIColor.blueColor()) {
            Alamofire.request(.GET, "https://0.0.0.0/app?func=\(patt.selectedSegmentIndex)&color=\(Color.Blue.rawValue)")
                .responseString { response in
                    print(response.result)
            }
        }
        else if sender.backgroundColor!.isEqual(UIColor.purpleColor()) {
            Alamofire.request(.GET, "https://0.0.0.0/app?func=\(patt.selectedSegmentIndex)&color=\(Color.Purple)")
                .responseString { response in
                    print(response.result)
            }
        }
        else if sender.backgroundColor!.isEqual(UIColor.whiteColor()) {
            Alamofire.request(.GET, "https://0.0.0.0/app?func=\(patt.selectedSegmentIndex)&color=\(Color.White.rawValue)")
                .responseString { response in
                    print(response.result)
            }
        }
        else if sender.backgroundColor!.isEqual(UIColor.orangeColor()) {
            Alamofire.request(.GET, "https://0.0.0.0/app?func=\(patt.selectedSegmentIndex)&color=\(Color.Orange.rawValue)")
                .responseString { response in
                    print(response.result)
            }
        }

    }

}
